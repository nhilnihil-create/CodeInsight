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

int main(int argc, char **argv)
{
	ll x, y, z, k; cin >> x >> y >> z >> k;
	vector<ll> va(x), vb(y), vc(z);
	REP(i, x) cin >> va[i];
	REP(i, y) cin >> vb[i];
	REP(i, z) cin >> vc[i];

	sort(ALL(va), greater<ll>());
	sort(ALL(vb), greater<ll>());
	sort(ALL(vc), greater<ll>());

	vector<ll> res;
	REP(a, x)REP(b, y)
		REP(c, z)
			if ((a+1)*(b+1)*(c+1) <= k) res.push_back(va[a]+vb[b]+vc[c]);
			else break;
				

	sort(ALL(res), greater<ll>());
	REP(i, k) std::cout << res[i] << std::endl;
}
