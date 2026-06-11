// In The Name Of God
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define sqr(A) ((A) * (A))
#define X first
#define Y second
#define MP make_pair
#define bsz  __builtin_popcount
#define all(A) A.begin(), A.end()
using namespace std;
using namespace __gnu_pbds;
template < typename T >
using ordered_set = tree < T , null_type , less < T > , rb_tree_tag , tree_order_statistics_node_update >;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int PR = 727;
const int INF = INT_MAX;
const ll LINF = LLONG_MAX;

const int N = 3e2 + 20;
int dp[N][N][N], n, k;
string s;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> s >> k; n = s.size();
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= k; j++)
			dp[i][i][j] = 1;
	for (int i = 0; i < n - 1; i++) {
		dp[i][i + 1][0] = (s[i] == s[i + 1] ? 2 : 1);
		for (int j = 1; j <= k; j++)
			dp[i][i + 1][j] = 2;
	}
	for (int gap = 3; gap <= n; gap++)
		for (int i = 0; i < n - gap + 1; i++) {
			int j = i + gap - 1;
			if (s[i] == s[j])
				dp[i][j][0] = dp[i + 1][j - 1][0] + 2;
			dp[i][j][0] = max({dp[i][j][0], dp[i + 1][j][0], dp[i][j - 1][0]});
			for (int x = 1; x <= k; x++) {
				if (s[i] == s[j])
					dp[i][j][x] = dp[i + 1][j - 1][x] + 2;
				dp[i][j][x] = max({dp[i][j][x], dp[i + 1][j - 1][x - 1] + 2, dp[i + 1][j][x], dp[i][j - 1][x]});
			}
		}
	cout << dp[0][n - 1][k] << endl;
}

