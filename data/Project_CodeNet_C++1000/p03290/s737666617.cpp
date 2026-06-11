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
#define F first
#define S second
#define lowbit(x) ((x)&(-(x)))
#define siz(v) (long long)(v).size()
typedef int64_t ll;
typedef uint64_t ull;
const double EPS  = 1e-8;
const int INF     = 0x3F3F3F3F;
const ll LINF     = 4611686018427387903;
const int MOD     = 1e9+7;
/*-----------------------------------------------------------------------------------------------------*/
#define int ll
int dp[1001];

signed main() {
	EmiliaMyWife

    int d, nd;
    cin >> d >> nd;

    for(int i = 0, a, b; i < d; i++) {
        cin >> a >> b;
        for(int j = 1000; j; j--) {
            for(int k = min(a, j); k; k--) {
                dp[j] = max(dp[j], dp[j-k]+((i+1)*100*k)+(a==k)*b);
            }
        }
    }
    for(int i = 0; i <= 1000; i++)
        if(dp[i] >= nd)
            return cout << i, 0;

	return 0;
}
