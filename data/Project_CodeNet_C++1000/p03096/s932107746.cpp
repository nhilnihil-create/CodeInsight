#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 2e5+10;
const int MOD = 1e9+7;
int a[MAX_N],b[MAX_N];
ll dp[MAX_N],sum[MAX_N];
int n;

void solve()
{
    n = unique(a+1,a+n+1)-(a+1);
	dp[0] = 1LL; 
	for(int i=1; i<=n; i++){
		dp[i] = dp[i-1];
		(dp[i]+=sum[a[i]])%=MOD;
		(sum[a[i]]+= dp[i-1])%=MOD;
	}
	printf("%lld\n",dp[n]);
}

int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
    solve();
	return 0;
}