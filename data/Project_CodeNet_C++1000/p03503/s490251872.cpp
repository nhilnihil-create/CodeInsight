#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

vector<vector<ll>> F;
vector<vector<ll>> P;

int main(int argc, char **argv)
{
	ll N; cin >> N;
	F.resize(N);

	REP(i, N)
	{
		REP(j, 10)
		{
			ll a; cin >> a;
			F[i].push_back(a);
		}
	}

	P.resize(N);

	REP(i, N)
	{
		REP(j, 11)
		{
			ll a; cin >> a;
			P[i].push_back(a);
		}
	}

	ll res{-INF};
	for (ll bits = 0; bits < (1 << 10); ++bits)
	{
		bool ok{false};
		ll tmp{0};
		REP(n, N)
		{
			ll cnt{0};
			REP(i, 10)
			{
				if ((bits & (1 << i)) && F[n][i])
				{
					++cnt;
				}
			}

			if (cnt > 0) ok = true;
			tmp += P[n][cnt];
		}
		if (ok)
			res = max(res, tmp);
	}

	std::cout << res << std::endl;
}
