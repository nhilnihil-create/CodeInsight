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
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	vector<ll> h(n);
	rep(i,n) cin >> x[i] >> y[i] >> h[i];
	vector<pair<ll, pii>> v(n);
	rep(i,n) {
		v[i].first = h[i];
		v[i].second.first = x[i];
		v[i].second.second = y[i];
	}
	sort(ALL(v), greater<>());
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			ll mh = v[0].first + abs(v[0].second.first - j) + abs(v[0].second.second - i);
			if (mh < 1) continue;
			bool b = true;
			for (int k = 0; k < n; k++) {
				if (v[k].first != max(mh - abs(v[k].second.first - j) - abs(v[k].second.second - i), 0ll)) b = false;
			}
			if (b) {
				cout << j << " " << i << " " << mh << endl;
				return;
			}
		}
	}
}

int main() {
	solve();
	return 0;
}
