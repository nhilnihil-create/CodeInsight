#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	ll ans = 1001001001001001;
	rep(i,n) cin >> v[i];
	for (int i = 0; i < n - k + 1; i++) {
		int l = v[i];
		int r = v[i + k - 1];
		if (0 <= l) {
			ans = min(ans,(ll) r);
		} else if (r <= 0) {
			ans = min(ans, (ll)abs(l));
		} else {
			ll t = (ll)abs(l) + abs(r) + min(abs(l), abs(r));
			ans = min(ans, t);
		}
	}
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}