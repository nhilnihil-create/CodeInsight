#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
typedef complex<ld> com;
constexpr int inf = 1000000000;
constexpr ll INF = 1000000000000000000;
constexpr ld EPS = 1e-12;
constexpr ld PI = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }

struct edge {
	int from, to, cost;
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int l;
	cin >> l;
	vector<edge> ans;
	int idx = 20;
	while (idx > 1) {
		if (l & 1) {
			if (l > 1) ans.pb({ 1, idx, l - 1 });
		}
		l >>= 1;
		ans.pb({ idx - 1, idx, 0 });
		if (l) ans.pb({ idx - 1,idx,l });
		idx--;
	}
	cout << 20 << ' ' << ans.size() << '\n';
	for (edge i : ans) cout << i.from << ' ' << i.to << ' ' << i.cost << '\n';
}