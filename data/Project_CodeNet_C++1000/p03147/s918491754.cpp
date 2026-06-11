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

signed main() {
	EmiliaMyWife

	int n, ans = 0;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	for(int k = 0; k <= 100; k++) {
		bool cur = 0;
		for(int i = 0; i < n; i++) {
			if(arr[i])
				ans += !cur, cur = 1, arr[i]--;
			else
				cur = 0;
		}
	}
	cout << ans << '\n';

	return 0;
}
