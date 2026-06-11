#include <bits/stdc++.h>
using namespace std;
#define MAXN 309
#define MAXM 4000009
#define MOD 1000000007
#define INF 1000000009
#define FOR(x,n) for(int x=0; x<n; x++)
#define FOR1e(x,n) for(int x=1; x<=n; x++)
typedef pair<int, int> ii;
typedef long long ll;

int dp[MAXN][MAXN][MAXN];
char w[MAXN];

int compute(int l, int r, int k) {
	if (l == r) return 1;
	if (l > r) return 0;

	if (w[l] == w[r]) return compute(l+1, r-1, k) + 2;
	int &ans = dp[l][r][k];
	if (ans != -1) return ans;

	ans = max(ans, compute(l+1, r, k));
	ans = max(ans, compute(l, r-1, k));
	if (k > 0) ans = max(ans, compute(l+1, r-1, k-1) + 2);
	return ans;
}
int main() {
	int k;
	scanf("%s %d", w, &k);
	int n = strlen(w);
	memset(dp, -1, sizeof(dp));
	cout << compute(0, n-1, k) << endl;
	return 0;
}