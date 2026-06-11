#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
#define REP(i, n) for(ll i = 0LL; i < (ll)(n); i++)
#define REPR(i, n) for(ll i = n-1; i >= 0LL; i--)
#define FOR(i, n, m) for(ll i = n; i < (ll)(m); i++)
#define PRINT(x) cout << x << endl
#define ALL(v) v.begin(), v.end()
#define INF (ll)1e18
#define INFD 1e18
#define PI 3.14159265358979
#define MOD 1000000007
#define vl vector<ll>

vector<ll> dx = {-1, 1, 0, 0};
vector<ll> dy = {0, 0, 1, -1};

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main()
{
	ll N;
	cin >> N;
	map<ll, ll> m;
	REP(i, N) {
		ll a;
		cin >> a;
		m[a]++;
	}
	for(P p : m) {
		if (p.second >= 3) {
			PRINT(0);
			return 0;
		}
		if (p.first == 12 && p.second >= 2) {
			PRINT(0);
			return 0;
		}
		if (p.first == 0 && p.second >= 1) {
			PRINT(0);
			return 0;
		}
	}
	vector<bool> v(48, false);
	v[0] = true;
	vector<ll> tmp;
	for(P p : m) {
		if (p.second == 2) {
			v[p.first] = true;
			v[24 - p.first] = true;
		}
		if (p.first == 12) v[12] = true;
		if (p.second == 1) tmp.push_back(p.first);
	}
	ll ans = 0;
	REP(i, pow(2, tmp.size())) {
		REP(j, tmp.size()) {
			if ((i >> j) & 1LL) {
				v[tmp[j]] = true;
			} else {
				v[24-tmp[j]] = true;
			}
		}
		REP(j, 24) v[j+24] = v[j];
		// REP(i, 24) cout << v[i] << " ";
		// cout << endl;
		ll mi = INF;
		REP(s, 24) {
			FOR(t, s+1, 48) {
				if (v[s] && v[t]){
					mi = min(mi, abs(s - t));
				}

			}
		}
		ans = max(mi, ans);
		REP(j, tmp.size()) {
			if ((i >> j) & 1LL) {
				v[tmp[j]] = false;
			} else {
				v[24-tmp[j]] = false;
			}
		}
	}
	PRINT(ans);
	return 0;
}
