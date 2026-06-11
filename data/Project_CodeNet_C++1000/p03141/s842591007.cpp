#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	int n;
	cin >> n;
	vector<int> v(n), u(n);
	rep(i,n) cin >> v[i] >> u[i];
	vector<pair<ll, pii>> w(n);
	rep(i,n) {
		w[i].first = (ll) v[i] + u[i];
		w[i].second.first = v[i];
		w[i].second.second = u[i];
	}
	ll ans = 0;
	sort(ALL(w), greater<>());
	rep(i,n) {
		if (i % 2 == 0) ans += w[i].second.first;
		else ans -= w[i].second.second;
	}
	cout << ans << endl;
}