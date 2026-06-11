#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod = 1000000007;
const long long inf = 1ll<<61;
typedef pair<int, int> P;
typedef pair<P, int> PP;
typedef pair<int, PP> PPP;
struct edge { int to; int to2; int cost; };
int p[5005];
vector<P>V;
int dp[5005][5005];
int rmin[5005];
signed main() {
	int n, a, b; cin >> n >> a >> b;
	rep(i, n)cin >> p[i];
	rep(i, n)V.push_back(P(p[i], i));
	sort(V.begin(), V.end());
	rep(i, 5005)rep(j, 5005)dp[i][j] = inf;
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		int pos = V[i - 1].second;
		rep(j, n + 1)rmin[j] = dp[i - 1][j];
		rep(j, n)rmin[j + 1] = min(rmin[j], rmin[j + 1]);
		rep(j, n + 1) {
			if (j == pos)dp[i][j] = rmin[j];
		else if (j < pos) {
			dp[i][j] = rmin[j] + b;
		}
		else {
			dp[i][j] = rmin[j] + a;
		}
		}
	}
	int ans = inf;
	rep(i, n + 1)ans = min(ans, dp[n][i]);
	cout << ans << endl;
}