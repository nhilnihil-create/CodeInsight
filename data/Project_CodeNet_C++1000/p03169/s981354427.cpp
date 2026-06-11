/*
--------------              |   /
      |                     |  /
      |                     | /
      |             *       |/          |    |         ------            *
      |                     |           |    |        /      \
      |             |       |\          |    |       |       |\          |
   \  |             |       | \         |    |       |       | \         |
    \ |             |       |  \        |    |        \     /   \        |
     V              |       |   \        \__/|         -----     \       |
*/
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(NULL);
#define mem(i,j) memset(i,j,sizeof (i));
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using uint = uint32_t;
const double EPS  = 1e-8;
const int INF     = 0x3F3F3F3F;
const ll LINF     = 4611686018427387903;
const int MOD     = 1e9+7;
/*-----------------------------------------------------------------------------------------------------*/

const int N = 300;
double dp[N + 2][N + 2][N + 2];

signed main() {
	EmiliaMyWife

	int n;
	cin >> n;
	int a[4] = {0};
	for(int i = 0, x; i < n; i++)
		cin >> x, a[x]++;
	for(int k = 0; k <= N; k++)
		for(int j = 0; j <= N; j++)
			for(int i = 0; i <= N; i++) {
				if(i)
					dp[i][j][k] += (dp[i - 1][j][k]) * i / n;
				if(j)
					dp[i][j][k] += (dp[i + 1][j - 1][k]) * j / n;
				if(k)
					dp[i][j][k] += (dp[i][j + 1][k - 1]) * k / n;
				if(i + j + k)
					dp[i][j][k] = (dp[i][j][k] + 1) * n / (i + j + k);
			}
	cout << setprecision(10);
	cout << dp[a[1]][a[2]][a[3]] << '\n';

	return 0;
}
