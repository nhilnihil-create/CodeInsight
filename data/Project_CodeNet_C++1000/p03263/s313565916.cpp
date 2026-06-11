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

const int INF = 1e9 + 10;

/* 
 * 
 *  0 1 0 0 0 1 0 1 0 0 
 *  0 0 0 1 0 0 1 0 1 0
 *  0 1 0 0 0 0 0 0 0 0 
 *  0 0 0 1 0 1 0 1 0 0 
 */

int H, W;
int a[505][505];

using Data = pair<pii, pii>;

signed main()
{
	cin >> H >> W;

	rep(i, H) rep(j, W) {
		cin >> a[i][j];
		a[i][j] %= 2;
	}

	vector<Data> ans;

	rep(i, H) {
		rep(j, W - 1) {
			if (a[i][j] % 2 == 1) {
				ans.PB(pii(i, j), pii(i, j + 1));
				a[i][j + 1] += 1;
			}
		}
	}

	rep(i, H - 1) {
		if (a[i][W - 1] % 2 == 1) {
			ans.PB(pii(i, W - 1), pii(i + 1, W - 1));
			a[i + 1][W - 1] += 1;
		}
	}

	cout << ans.size() << endl;
	for (Data &d : ans) {
		printf("%lld %lld %lld %lld\n", d.fst.fst + 1, d.fst.scd + 1, d.scd.fst + 1, d.scd.scd + 1);
	}
}

