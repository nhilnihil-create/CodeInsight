#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5000 + 10;
const ll INF = 1LL << 50;

int n, a[maxn], p[maxn]; ll A, B, dp[2][maxn], mn[maxn];

inline void upmin(ll &x, ll y) { x = min(x,y); }

ll get_val(int i, int j) { return (p[i] <= j) ? (A) : (B); }

int main() {
	scanf("%d%lld%lld", &n, &A, &B);
	for(int i = 1;i <= n;i ++) scanf("%d", &a[i]), p[a[i]] = i;
	int cur = 1, pre = 0;
	for(int i = 0;i < p[1];i ++) dp[cur][i] = B;
	dp[cur][p[1]] = 0;
	for(int i = p[1] + 1;i <= n;i ++) dp[cur][i] = A;
	mn[0] = dp[cur][0];
	for(int i = 1;i <= n;i ++) mn[i] = min(mn[i - 1],dp[cur][i]);
	for(int i = 2;i <= n;i ++) {
		cur = pre; pre ^= 1;
		for(int j = 0;j <= n;j ++) dp[cur][j] = INF;
		for(int j = 0;j <= n;j ++) {
			upmin(dp[cur][j],mn[j] + get_val(i,j));
			if(j == p[i]) upmin(dp[cur][j],mn[j - 1]);
		}
		mn[0] = dp[cur][0];
		for(int j = 1;j <= n;j ++) mn[j] = min(mn[j - 1],dp[cur][j]);
	}
	ll Ans = mn[n];
	printf("%lld\n", Ans);
	return 0;
}
