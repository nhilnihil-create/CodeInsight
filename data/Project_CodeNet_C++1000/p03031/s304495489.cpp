#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

using namespace std;

static const ll INF = 1e15;

int main() {
	ll n, m;
	cin >> n >> m;
	vector<ll> vs(m);
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		ll bits = 0;
		rep(j, k) {
			ll a;
			cin >> a;
			a--;
			bits |= (1LL << a);
		}
		vs[i] = bits;
	}
	vector<ll> ps(m);
	rep(i, m) {
		cin >> ps[i];
	}
	ll sum = 0;
	rep(i, 1LL << n) {
		bool ok = true;
		rep(j, m) {
			ll s = i & vs[j];
			if (__builtin_popcountll(s) % 2 != ps[j]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			sum++;
		}
	}
	cout << sum << endl;
	return 0;
}
