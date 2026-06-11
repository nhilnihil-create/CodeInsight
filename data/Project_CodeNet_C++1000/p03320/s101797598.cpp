#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> pip;
const ll INF = 1e9+100;
const ll INFL = 1e18+100;
const ll MOD = 1e9+7;
const double EPS  = 1e-10;
const bool debug = 0;
//-----------------------------------//

int digitsum(ll x) {
	int res = 0;
	while (x > 0) {
		res += x % 10;
		x /= 10;
	}
	return res;
}

double calc(ll n) {
	int ds = digitsum(n);
	return (double)n / ds;
}

ll func(ll n) {
	pair<double, ll> res(calc(n), n);

	ll div = 1, x = n;
	
	while (div < 10000000000000000ll) {
		if (x % 10 == 9) {
			x /= 10;
			div *= 10;
		}
		ll m = (x + 1) * div - 1;
		x++;
		if (n > m) continue;
		pair<double, ll> cur(calc(m), m);
		chmin(res, cur);
	}

	return res.se;
}

int main() {
	int K;
	cin >> K;

	vector<ll> ans;
	ans.push_back(1);
	while (ans.back() < 1000000000000000ll) {
		ans.push_back(func(ans.back() + 1));
	}

	REP(i, K) printf("%lld\n", ans[i]);

	return 0;
}
