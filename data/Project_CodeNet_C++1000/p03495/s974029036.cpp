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
#define rep(i, n) for (int i=0;i<(int)(n);++i)
#define rep1(i, n) for (int i=1;i<=(int)(n);++i)
#define range(i, l, r) for (int i=l;i<(int)(r);++i)
#define rrange(i, l, r) for (int i=r-1;i>=(int)(l);--i)
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

int counter[200010];

signed main()
{
	int N, K; cin >> N >> K;
	vi A(N);
	rep(i, N) {
		counter[read()]++;
	}
	vector<pii> data;
	rep(i, N + 1) {
		if (counter[i] > 0) {
			data.PB(counter[i], i);
		}
	}

	sort(all(data));

	int sz = data.size();

	if (sz <= K) {
		cout << 0 << endl;
	} else {
		int ans = 0;

		rep(i, sz - K) {
			ans += data[i].fst;
		}

		cout << ans << endl;
	}
}


