#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, a, b) for(ll i = a; i < b; i++)
#define out(x) std::cout << x << '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define sz(x) ((int)(x).size())
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INF = INT_MAX / 2;
const ll  inf = LLONG_MAX / 2;
const int mod = 1000000007;
const int MAX_N = 101010;
const long double PI = acos(-1);

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	/*------------------------------*/

	ll n;
	cin >> n;

	vector<ll> x(n), y(n), h(n);
	ll one_i = -1;
	rep(i, n) {
		cin >> x[i] >> y[i] >> h[i];
		if (h[i] >= 1) one_i = i;
	}

	ll ansx = -1, ansy = -1, ansh = -1;
	for (ll xx = 0; xx <= 100; xx++) {
		for (ll yy = 0; yy <= 100; yy++) {
			ll hh = h[one_i] + llabs(xx - x[one_i]) + llabs(yy - y[one_i]);

			bool ok = true;
			rep(i, n) {
				if (h[i] >= 1 && (hh - h[i] != llabs(xx - x[i]) + llabs(yy - y[i]))) {
					ok = false;
				}
				if (h[i] == 0 && (hh > llabs(xx - x[i]) + llabs(yy - y[i]))) {
					ok = false;
				}
			}
			if (ok) {
				ansx = xx;
				ansy = yy;
				ansh = hh;
			}
		}
	}

	cout << ansx << " " << ansy << " " << ansh << endl;

	return 0;
}