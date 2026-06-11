#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=10;
int n,f[N][N][N][N],a[N];
int dp(int i,int full,int sum1,int sum2,int sum3,int have0)
{
	if(f[i][sum1][sum2][sum3]!=-1&&!full&&!have0) return f[i][sum1][sum2][sum3];
	if(!i)
	{
		if(sum1&&sum2&&sum3) return 1;
		else return 0;
	}
	int end=full?a[i]:9,sum=0;
	for(int j=0;j<=end;j++)
	{
		if(j==0&&have0) sum+=dp(i-1,full&(end==0),sum1,sum2,sum3,1);
		else if(j==3) sum+=dp(i-1,full&(end==3),sum1+1,sum2,sum3,0);
		else if(j==5) sum+=dp(i-1,full&(end==5),sum1,sum2+1,sum3,0);
		else if(j==7) sum+=dp(i-1,full&(end==7),sum1,sum2,sum3+1,0);
	}
	if(!full&&!have0) f[i][sum1][sum2][sum3]=sum;
	return sum;
}
int calc(int x)
{
	memset(f,-1,sizeof(f));
	int t=0;
	while(x) a[++t]=x%10,x/=10;
	return dp(t,1,0,0,0,1);
}
int main()
{
	scanf("%d",&n);
	printf("%d",calc(n));
	return 0;
}