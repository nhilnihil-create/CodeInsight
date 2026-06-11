#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n;
	cin >> n;
	V<V<bool>> f(n, V<bool>(10, false));
	rep(i, n)rep(j, 10) {
		int k;
		cin >> k;
		if (k)f[i][j] = true;
	}
	vvi p(n, vi(11));
	rep(i, n)rep(j, 11)cin >> p[i][j];

	ll ans = -LINF;
	rep(i, 1 << 10) {
		if (i == 0)continue;

		vi c(n, 0);

		rep(j, 10) {
			if (!((i >> j) & 1))continue;
			rep(k, n)if (f[k][j])c[k]++;
		}

		ll prof = 0;
		rep(j, n)prof += p[j][c[j]];
		ans = max(ans, prof);

	}

	cout << ans << endl;

}