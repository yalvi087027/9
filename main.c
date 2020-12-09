#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void treugol1(int n, double a[n][n], double *b, int k)
{
    if(k==n-1)
    {
        return;
    }
    int m=k;
    for(int i = k; i < n; i++)
    {
        if (fabs(a[i][k]) > 0.01)
        {
            m = i;
            break;
        }
    }
    if(m!=k)
    {
        for(int i = k; i < n; i++)
        {
            double t = a[k][i];
            a[k][i]=a[m][i];
            a[m][i]=t;
        }
        double t = b[k];
        b[k]=b[m];
        b[m]=t;
    }
    for(int i = k+1; i < n; i++)
    {
        if(fabs(a[i][k])>=0.01)
        {
            double d = a[i][k]/a[k][k];
            for(int j = k; j < n; j++)
            {
                a[i][j]-=a[k][j]*d;
            }
            b[i]-=b[k]*d;
        }
    }
    treugol1(n, a, b, k + 1);
}

void treugol2(int n, double a[n][n], double *b, int k)
{
    if(k==0)
    {
        return;
    }
    int m=-1;
    for(int i = k; i >= 0; i-=1)
    {
        if (fabs(a[i][k]) > 0.01)
        {
            m = i;
            break;
        }
    }
    if(m!=k)
    {
        for(int i = k; i >=0; i-=1)
        {
            double t = a[k][i];
            a[k][i]=a[m][i];
            a[m][i]=t;
        }
        double t = b[k];
        b[k]=b[m];
        b[m]=t;
    }
    for(int i = k-1; i >= 0; i-=1)
    {
        if(fabs(a[i][k])>=0.01)
        {
            double d = a[i][k]/a[k][k];
            for(int j = n-1; j >= 0; j-=1)
            {
                a[i][j]-=a[k][j]*d;
            }
            b[i]-=b[k]*d;
        }
    }
    treugol2(n, a, b, k - 1);
}

void treugol3(int n, double a[n][n], double b[n][n], int k)
{
    if(k==n-1)
    {
        return;
    }
    int m=k;
    for(int i = k; i < n; i++)
    {
        if (fabs(a[i][k]) > 0.01)
        {
            m = i;
            break;
        }
    }
    if(m!=k)
    {
        for(int i = k; i < n; i++)
        {
            double t = a[k][i];
            a[k][i]=a[m][i];
            a[m][i]=t;
        }
        for(int i = 0; i < n; i++)
        {
            double t = b[k][i];
            b[k][i]=b[m][i];
            b[m][i]=t;
        }
    }
    for(int i = k+1; i < n; i++)
    {
        if(fabs(a[i][k])>=0.01)
        {
            double d = a[i][k]/a[k][k];
            for(int j = k; j < n; j++)
            {
                a[i][j]-=a[k][j]*d;
            }
            for(int j = 0; j < n; j++)
            {
                b[i][j]-=b[k][j]*d;
            }
        }
    }
    treugol3(n, a, b, k + 1);
}

void treugol4(int n, double a[n][n], double b[n][n], int k)
{
    if(k==0)
    {
        return;
    }
    int m=-1;
    for(int i = k; i >= 0; i-=1)
    {
        if (fabs(a[i][k]) > 0.01)
        {
            m = i;
            break;
        }
    }
    if(m!=k)
    {
        for(int i = k; i >=0; i-=1)
        {
            double t = a[k][i];
            a[k][i]=a[m][i];
            a[m][i]=t;
        }
        for(int i = n-1; i >=0; i-=1)
        {
            double t = b[k][i];
            b[k][i]=b[m][i];
            b[m][i]=t;
        }
    }
    for(int i = k-1; i >= 0; i-=1)
    {
        if(fabs(a[i][k])>=0.01)
        {
            double d = a[i][k]/a[k][k];
            for(int j = n-1; j >= 0; j-=1)
            {
                a[i][j]-=a[k][j]*d;
            }
            for(int j = n-1; j >= 0; j-=1)
            {
                b[i][j]-=b[k][j]*d;
            }
        }
    }
    treugol4(n, a, b, k - 1);
}

int main()
{
    while (1 > 0)
    {
        int nomer;

        printf("\nvvedite nomer zadachi:\n");
        scanf("%d", &nomer);
        if(nomer==1)
        {
            printf("vvedite m i n:\n");
            int m;
            int n;
            scanf("%d",&m);
            scanf("%d",&n);
            int a[m][n];
            printf("vvedite matricu m*n");
            for(int i = 0; i < m; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    printf("a[%d][%d]=\n",i,j);
                    scanf("%d", &a[i][j]);
                }
            }
            printf("tuda\n");
            int b[m * n];
            for(int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    b[n * j + i] = a[j][i];
                    printf("%d ",b[n * j + i]);
                }
            }

            int c[m][n];
            printf("obratno\n");
            for(int k = 0; k < m * n - 1; ++k)
            {
                c[k % m][k % n] = b[k];
            }
            for(int i = 0; i < m; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    printf("%d ",c[i][j]);
                }

                printf("\n");
            }
        }
        if(nomer==2)
        {
            printf("vvedite m ggg n:\n");
            int m, n;
            scanf("%d%d", &m, &n);
            int a[m][n], b[m][n];
            for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    a[i][j] = 1 + abs(i - j);
                }
            }
            for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    b[i][j] = 0;
                }
            }
            int d = 1;
            int ggg = 0;
            int hhh = 0;
            while (d <= m * n)
            {
                while(hhh < n - 1 && b[ggg][hhh + 1] == 0)
                {
                    b[ggg][hhh] = d;
                    d+=1;
                    hhh+=1;
                }
                while(ggg < m - 1 && b[ggg + 1][hhh] == 0)
                {
                    b[ggg][hhh] = d;
                    d+=1;
                    ggg+=1;
                }
                while(0 < hhh && b[ggg][hhh - 1] == 0)
                {
                    b[ggg][hhh] = d;
                    d+=1;
                    hhh-=1;
                }
                while(0 < ggg && b[ggg - 1][hhh] == 0)
                {
                    b[ggg][hhh] = d;
                    d+=1;
                    ggg-=1;
                }
                if(b[ggg + 1][hhh] != 0 && b[ggg][hhh + 1] != 0 && b[ggg - 1][hhh] != 0 && b[ggg][hhh - 1] != 0 && b[ggg][hhh] == 0)
                {
                    b[ggg][hhh]=d;
                    d+=1;
                }
            }

            for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    printf("%d ", a[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    printf("%d ", b[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }
        if(nomer==5)
        {
            printf("vvedite kolichestvo peremennih:\n");
            int n;
            scanf("%d",&n);
            printf("vvedite matricu bez stolbca constant:\n");
            double a[n][n];
            for(int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; ++j)
                {
                    scanf("%lf",&a[i][j]);
                }
            }
            double b[n];
            printf("vvedite stolbec constant:\n");
            for (int i = 0; i < n; ++i)
            {
                scanf("%lf",&b[i]);
            }
            treugol1(n, a, b, 0);
            printf("verhnetreugolnaya matrica:\n");
            for(int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; ++j)
                {
                    printf("%lf ",a[i][j]);
                }
                printf("%lf\n",b[i]);
            }
            treugol2(n, a, b, n - 1);
            printf("\ndiagonalnaya matrica:\n");
            for(int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; ++j)
                {
                    printf("%lf ",a[i][j]);
                }
                printf("%lf\n",b[i]);
            }
            printf("\nreshenie sistemi:\n");
            for(int i = 0; i < n; i++)
            {
                printf("x[%d] = %lf\n", i +1, b[i]/a[i][i]);
            }
        }
        if(nomer==6)
        {
            printf("vvedite poryadok matrici:\n");
            int n;
            scanf("%d",&n);
            printf("vvedite matricu:\n");
            double a1[n][n];
            double a2[n][n];
            for(int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; ++j)
                {
                    scanf("%lf",&a1[i][j]);
                    a2[i][j]=a1[i][j];
                }
            }
            double b[n][n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if(i==j)
                    {
                        b[i][j]=1;
                    }else
                    {
                        b[i][j]=0;
                    }
                }
            }
            treugol3(n, a1, b, 0);
            treugol4(n, a1, b, n - 1);
            printf("\nobratnaya matrica:\n");
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    b[i][j]/=a1[i][i];
                    printf("%lf ",b[i][j]);
                }
                printf("\n");
            }
            double c[n][n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    c[i][j]=0;
                }
            }
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    for(int k = 0; k < n; k++)
                    {
                        c[i][j] += a2[i][k] * b[k][j];
                    }
                }
            }
            printf("\nproverka:\n");
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    printf("%lf ",c[i][j]);
                }
                printf("\n");
            }
        }
    }
}
