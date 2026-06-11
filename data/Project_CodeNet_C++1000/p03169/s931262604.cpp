#include <iostream>
using namespace std;
int arr[4],n;
double dp[305][305][305];//dp[i][j][k]代表i个装有一个寿司的盘子，j个两个寿司的盘子，k个三个寿司的盘子的情况下吃完寿司的期望次数 
double dfs(int a,int b,int c)
{
    if(a==0&&b==0&&c==0)
	  return 0;
    if(dp[a][b][c]>0)
	  return dp[a][b][c];
    double ans=1.0*n/(a+b+c);//共有n个盘子，还剩a+b+c个盘子有寿司时，下一次吃到寿司的期望次数为n/(a+b+c) (用极限证明) 
    if(a)//吃到的是剩余一个寿司的盘子中的寿司,概率为a/(a+b+c) 
	  ans+=(1.0*a/(a+b+c))*dfs(a-1,b,c);//a/(a+b+c)的概率变成(a-1,b,c)状态 
    if(b)//吃到的是剩余两个寿司的盘子中的寿司 
	  ans+=(1.0*b/(a+b+c))*dfs(a+1,b-1,c);//b/(a+b+c)的概率变成(a+1,b-1,c)的状态 
    if(c)//吃到的是剩余三个寿司的盘子中的寿司 
	  ans+=(1.0*c/(a+b+c))*dfs(a,b+1,c-1);//c/(a+b+c)的概率变成(a,b+1,c-1)状态 
    return dp[a][b][c]=ans;//吃完当前状态(a,b,c)寿司的期望次数为上一状态吃完寿司的期望次数加上当前吃一个寿司的期望次数
}
int main()
{
    int d;
    scanf("%d",&n);
    for(int i = 1;i<=n;++i)
    {
        scanf("%d",&d);
        arr[d]++;
    }
    printf("%.10f\n",dfs(arr[1],arr[2],arr[3]));
    return 0;
}