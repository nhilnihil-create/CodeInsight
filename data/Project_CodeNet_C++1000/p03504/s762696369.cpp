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
	ll N, C; cin >> N >> C;
	ll MAX = 100010;
	vector<vector<ll>> imosc(C, vector<ll>(MAX, 0));
	vector<ll> imos(100010, 0);
	REP(i, N)
	{
		ll s, t, c; cin >> s >> t >> c;
		--c;
		imos[s-1]++;
		imos[t]--;
		imosc[c][s-1]++;
		imosc[c][t]--;
	}

	REP(i, MAX-1)
		imos[i+1] += imos[i];

	REP(i, C)
	{
		REP(k, MAX-1)
		{
			imosc[i][k+1] += imosc[i][k];
		}
	}


	ll res{0};
	REP(i, MAX)
	{
		ll tmp = imos[i];
		REP(j, C)
		{
			tmp -= max(0ll, imosc[j][i]-1);
		}

		res = max(res, tmp);
	}

	std::cout << res << std::endl;
}
