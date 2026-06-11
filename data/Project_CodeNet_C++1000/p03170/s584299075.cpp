#include<iostream>
using namespace std;
int dp[100001];
int a[101];
int main()
{
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=0;i<=k;i++)
		for(int j=1;j<=n;j++)
			if(i>=a[j]&&!dp[i-a[j]])dp[i]=1;
	if(dp[k]==1)cout<<"First";
	else cout<<"Second";
	return 0;
}