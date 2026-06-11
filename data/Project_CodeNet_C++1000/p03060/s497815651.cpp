#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep_lr(i,l,r) for(int i=(l);i<(r);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr int INF = INT_MAX >> 1;
constexpr ll LINF = 5000000000000000LL;
constexpr int MOD = 1000000007;

int main() {

	int n;
	cin >> n;
	vi v(n), c(n);
	rep(i, n)cin >> v[i];
	rep(i, n)cin >> c[i];

	int ans = 0;
	rep(i, 1 << n) {

		int x = 0, y = 0;
		rep(j, n) {
			if ((i >> j) & 1) {
				x += v[j];
				y += c[j];
			}
		}
		ans = max(ans, x - y);
	}
	cout << ans << endl;
}