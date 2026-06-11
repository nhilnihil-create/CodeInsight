#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define LL long long
#define INF 0x3f3f3f3f
#define Inf 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef pair<int,int>pii;
int n;
vector<LL>dp;
vector<vector<LL>>a;
int main(){
	cin>>n;
	a.resize(n,vector<LL>(n));
	dp.resize(1<<n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	for(int i=1;i<1<<n;i++)
		for(int j=0;j<n-1;j++)if(1<<j&i)
			for(int k=j+1;k<n;k++)if(1<<k&i)
				dp[i]+=a[j][k];
	for(int i=1;i<1<<n;i++)
		for(int j=(i-1)&i;j;j=(j-1)&i)
			dp[i]=max(dp[i],dp[j]+dp[i^j]);
	cout<<dp[(1<<n)-1]<<endl;
	return 0;
}
