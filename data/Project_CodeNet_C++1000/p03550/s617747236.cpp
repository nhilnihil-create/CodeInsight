#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <functional>
#include <climits>
#include <cstring>

using namespace std;

#define int long long
#define rep(i, n) for (int i=0;i<(int)n;++i)
#define rep1(i, n) for (int i=1;i<=(int)n;++i)
#define unless(a) if(!(a))
#define all(a) begin(a),end(a)
#define fst first
#define scd second
#define PB emplace_back
#define PPB pop_back

using vi=vector<int>;
using pii=pair<int, int>;

bool chmin(int&a,int b){return a>b?(a=b,true):false;}
bool chmax(int&a,int b){return a<b?(a=b,true):false;}
int read(){int a;scanf("%lld",&a);return a;}

using Data = pair<pii, int>;

int N, _, W;
int dp[2][2005];
vi a;

int DP(int p, int i)
{
	if (dp[p][i] != -1) return dp[p][i];

	int &res = dp[p][i];

	res = abs(a[i] - a[N]);

	if (p == 0) {
		for (int j = i + 1; j < N; ++j) {
			chmax(res, DP(!p, j));
		}
	} else {
		for (int j = i + 1; j < N; ++j) {
			chmin(res, DP(!p, j));
		}
	}

	return res;
}

signed main()
{
	cin >> N >> _ >> W;
	a.resize(N+1);
	a[0] = W;
	rep1(i, N) cin >> a[i];

	memset(dp, -1, sizeof(dp));
	cout << DP(0, 0) << endl;
}
