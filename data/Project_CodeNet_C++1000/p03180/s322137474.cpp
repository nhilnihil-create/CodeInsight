/*
数据不清空，爆零两行泪。
多测不读完，爆零两行泪。
边界不特判，爆零两行泪。
贪心不证明，爆零两行泪。
D P 顺序错，爆零两行泪。
大小少等号，爆零两行泪。
变量不统一，爆零两行泪。
越界不判断，爆零两行泪。
调试不注释，爆零两行泪。
溢出不 l l，爆零两行泪。
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=16;
int n;
int a[N+1][N+1];
int sum[1<<N];
int dp[1<<N];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>a[i][j];
	for(int i=0;i<1<<n;i++)
		for(int j=1;j<=n;j++)for(int k=j+1;k<=n;k++)
			if(i&1<<j-1&&i&1<<k-1)sum[i]+=a[j][k];
	for(int i=0;i<1<<n;i++)
		for(int j=i;j;j=j-1&i)
			dp[i]=max(dp[i],sum[j]+dp[i^j]);
	cout<<dp[(1<<n)-1];
	return 0;
}