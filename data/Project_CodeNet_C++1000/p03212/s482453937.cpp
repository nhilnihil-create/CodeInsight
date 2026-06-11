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
set<int> s;
int solve(int now, int n) {
	//cerr << now << '\n';
	if(now > n)
		return 0;
	if(now <= n) {
		int w = now;
		bool x[10] = {0};
		for(; w; w/=10)
			x[w%10] = 1;
		if(x[3]&&x[5]&&x[7])
			s.insert(now);
	}
	int res = 0;
	now*=10;
	res += solve(now+3, n)+solve(now+5, n)+solve(now+7, n);
	return res;
}

signed main() {
	EmiliaMyWife

	int n;
	cin >> n;
	solve(0, n);
	cout << s.size() << '\n';
	//for(int a : s)
		//cout << a << ' ';

	return 0;
}
