#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n;
	cin >> n;
	vi a(n);
	rep(i, n)cin >> a[i];

	bool ng = false;
	rep(i, n)if (i + 1 < a[i])ng = true;
	if (ng) { cout << -1 << endl;return 0; }

	vi ans(0);

	rep(i, n) {

		bool find = false;
		vi aa(0);
		rep(j, a.size()) {
			if (!find && a[a.size() - 1 - j] == a.size() - j) {
				ans.push_back(a.size() - j);
				find = true;
			}
			else aa.push_back(a[a.size() - 1 - j]);
		}

		reverse(all(aa));
		a = aa;

	}

	reverse(all(ans));

	if (ans.size() < n)cout << -1 << endl;
	else rep(i, n)cout << ans[i] << endl;

}