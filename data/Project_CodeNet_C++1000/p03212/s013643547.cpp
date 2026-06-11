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

ll p[3] = {3, 5, 7};

bool is_753(ll x, int a=0, int b=0, int c=0) {
	if (x == 0) return a && b && c;
	ll m = x % 10;
	if (m == 3) return is_753(x/10, a+1, b, c);
	else if (m == 5) return is_753(x/10, a, b+1, c);
	else return is_753(x/10, a, b, c+1);
}

void solve() {
	ll n;
	cin >> n;
	queue<ll> q;
	rep(i,3) {
		q.push(p[i]);
	}
	ll ans = 0;
	while (!q.empty()) {
		ll t = q.front(); q.pop();
		if (t <= n) {
			if (is_753(t)) ans++;
			for (int i = 0; i < 3; i++) {
				ll m = t * 10 + p[i];
				q.push(m);
			}
		}
	}
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}