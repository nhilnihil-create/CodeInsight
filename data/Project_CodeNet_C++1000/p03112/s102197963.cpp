#include "bits/stdc++.h"

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define bit(n) (1LL << (n))
#define sz(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define en '\n'
#define pb push_back
#define P pair<int, int>

typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INF = (int)1e9;
const ll  inf = (ll)1e18;
const int mod = 1000000007;

void chmin(ll &a, ll b) {
	if (a > b) a = b;
}

template <class T>
int former(const vector<T> &v, T x) {
	return upper_bound(v.begin(), v.end(), x) - v.begin() - 1;
}

template <class T>
int latter(const vector<T> &v, T x) {
	return lower_bound(v.begin(), v.end(), x) - v.begin();
}

int main() {
	int A, B, Q;
	cin >> A >> B >> Q;
	vector<ll> s(A), t(B);
	for (int i = 0; i < A; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < B; i++) {
		cin >> t[i];
	}

	s.push_back(inf); s.push_back(-inf); sort(s.begin(), s.end());
	t.push_back(inf); t.push_back(-inf); sort(t.begin(), t.end());

	for (int i = 0; i < Q; i++) {
		ll x;
		cin >> x;
		
		ll res = inf;

		for (int i = 0; i < 2; i++) {
			ll first = (i ? s[former(s, x)] : s[latter(s, x)]);

			for (int j = 0; j < 2; j++) {
				ll second = (j ? t[former(t, first)] : t[latter(t, first)]);
				chmin(res, abs(x - first) + abs(first - second));
			}
		}

		for (int i = 0; i < 2; i++) {
			ll first = (i ? t[former(t, x)] : t[latter(t, x)]);

			for (int j = 0; j < 2; j++) {
				ll second = (j ? s[former(s, first)] : s[latter(s, first)]);
				chmin(res, abs(x - first) + abs(first - second));
			}
		}

		cout << res << endl;
	}
}