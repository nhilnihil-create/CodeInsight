#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)
const ll INF = 1e15;
int n, a, b, p;
ll dp[5005], ans = INF;
int main(){
	scanf("%d%d%d", &n, &a, &b);
	rep(i,n){
		scanf("%d", &p);
		ll m = INF;
		rep(j,p){
			m = min(m,dp[j]);
			dp[j] += a;
		}
		dp[p] = m;
		for(int j=p+1; j<=n; j++) dp[j] += b;
	}
	rep(i,n+1) ans = min(ans, dp[i]);
	printf("%lld\n", ans);
}