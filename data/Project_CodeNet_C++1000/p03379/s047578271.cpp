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

    int n;
    cin >> n;
    vector<pair<int,int>> arr(n);
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    int x = n/2;
    for(int i = 0; i < n; i++) {
        if(i < x)
            ans[arr[i].second] = arr[x].first;
        else
            ans[arr[i].second] = arr[x-1].first;
    }
    for(int i = 0; i < n; i++)
        cout <<ans[i] << '\n';

	return 0;
}
