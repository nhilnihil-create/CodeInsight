// Algorithm: Brute-force

#include "cstdio"
using namespace std;

const int maxn=30+10;
int n,c,d[maxn][maxn],t[4][maxn],x,y,z,ans;

int main()
{
    ans=0x7fffffff;    // 先把答案记为一个极大值，出现更小的就更新
    scanf("%d%d",&n,&c);

    register int i,j,k,l;
    for(i=1;i<=c;i++)
    {
        // 输入D矩阵(i-j)为颜色i变为颜色j的代价为(i,j)
        for(j=1;j<=c;j++)
        {
            scanf("%d",&d[i][j]);
        }
    }

    for(i=1;i<=n;i++)
    {
        // 输入矩阵C
        for(j=1;j<=n;j++)
        {
            scanf("%d",&x);
            t[(i+j)%3][x]++;    // 计算横坐标加纵坐标mod3的数值,颜色为x的个数+1
        }
    }

    for(i=1;i<=c;i++)
    {
        // 枚举坐标余数为0的颜色，统一变成颜色i，其代价之和为x
        // 比如例1中，坐标为1行2列的余数为(1+2)%3=0，其值2，变成i=1则D_21=1
        // 坐标2列1行的余数为(2+1)%3=0，其值为3，变成i=1则有D_31=31
        // x = D_21 + D_31 = 2
        x=0;
        for(j=1;j<=c;j++)
        {
            x+=t[0][j]*d[j][i];
        }

        for(j=1;j<=c;j++)
        {    // 枚举余数为1的颜色，统一变成颜色j,其代价之和为y
            if(j==i)
            {
                continue;    // 不同余数的颜色不能相同
            }

            y=0;
            for(k=1;k<=c;k++)
            {
                y+=t[1][k]*d[k][j];
            }

            for(k=1;k<=c;k++)
            {
                // 枚举坐标余数为2的颜色，统一变成颜色k,其代价之和为z
                if(k==j || k==i)
                {
                    continue;    // 不同余数的颜色不能相同
                }

                z=0;
                for(l=1;l<=c;l++)
                {
                    z+=t[2][l]*d[l][k];
                }

                if(ans>x+y+z)
                {
                    // 如果当前转换的代价和比之前的最优答案更小，就更新代价和
                    ans=x+y+z;
                }
            }
        }
    }

    printf("%d",ans);
    return 0;
}