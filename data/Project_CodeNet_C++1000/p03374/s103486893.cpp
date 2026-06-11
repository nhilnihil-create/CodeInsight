#include<iostream>
#include<algorithm>
#include<cmath> 
using namespace std;
const int maxn=1e5+5;
//int a[maxn];
long long dp[2][maxn];
long long cp[2][maxn];  
long long x[maxn], v[maxn];
int main()
{
	long long n,c,sum;
	scanf("%lld%lld",&n,&c);
	for(int i=1;i<=n;i++) 
	scanf("%lld%lld",&x[i],&v[i]); 
	for (int i=0;i<=n+1;i++)
	dp[0][i]=dp[1][i]=-0x3f3f3f3f;
	for(int i=1;i<=n;i++) 
	{ 
        sum+=v[i];    
        dp[0][i]=max(dp[0][i-1],sum-x[i]);  
        cp[0][i]=sum-2*x[i];  
    }  
    sum=0;  
    for(int i=n;i>=1;i--) 
	{ 
        sum+=v[i];  
        dp[1][i]=max(dp[1][i+1],sum-(c-x[i]));  
        cp[1][i]=sum-2*(c-x[i]);  
    }  
    long long ans=max(dp[0][n],dp[1][1]);  
    for(int i=1;i<=n;i++) 
	{  
        ans=max(ans,cp[0][i]+dp[1][i + 1]);  
        ans=max(ans,cp[1][i]+dp[0][i - 1]);  
    }  
    printf("%lld\n", ans>0?ans:0);   
} 