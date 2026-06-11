#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	ll n;
	cin >> n;
	set<ll> s;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			s.insert(i);
			s.insert(n/i);
		}
	}

	ll ans = 0;
	for (ll x: s) {
		ll m = x - 1;
		if (m == 0) continue;
		ll a = n / m;
		ll b = n % m;
		if (a == b) ans += m;
	}
	cout << ans << endl;
}