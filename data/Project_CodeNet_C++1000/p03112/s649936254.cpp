#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

const ll MOD = 1e9+7;
// const ll MOD = 998244353;
const ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

ll A, B, Q;
vector<ll> s, t;

int main(int argc, char **argv)
{
	cin >> A >> B >> Q;
	
	s.resize(A+2);
	REP(i, A) cin >> s[i+1];
	s[0] = -INF;
	s[A+1] = INF;
	
	t.resize(B+2);
	REP(i, B) cin >> t[i+1];
	t[0] = -INF;
	t[B+1] = INF;

	REP(_, Q)
	{
		ll x; cin >> x;
		ll res{INF};
		auto jin_r_it = lower_bound(ALL(s), x);
		auto jin_l_it = prev(upper_bound(ALL(s), x));
		auto tera_r_it = lower_bound(ALL(t), x);
		auto tera_l_it = prev(upper_bound(ALL(t), x));

		ll jinld = abs(*jin_l_it - x);
		ll jinrd = abs(*jin_r_it - x);
		ll terald = abs(*tera_l_it - x);
		ll terard = abs(*tera_r_it - x);

		// right
		res = min(res, max(jinrd, terard));
		// left , right
		res = min(res, jinrd+terard);
		res = min(res, max(jinrd, terald)+min(jinrd, terald)*2);
		res = min(res, max(terard, jinld)+min(terard, jinld)*2);
		res = min(res, max(jinld, terald));

		std::cout << res << std::endl;
	}
}
