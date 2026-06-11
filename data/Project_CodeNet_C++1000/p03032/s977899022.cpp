#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

ll N, K;
ll V[100];

int main(int argc, char **argv)
{
	cin >> N >> K;
	REP(i, N) cin >> V[i];

	ll M = min(K, N);

	ll res{-INF};
	for (ll l = 0; l <= M; ++l)
	{
		for (ll r = 0; r <= M; ++r)
		{
			if (l + r > M) continue;

			ll th = K - l - r;
			
			vector<ll> tmp;
			for (ll i = 0; i < l; ++i)
				tmp.push_back(V[i]);
			for (ll i = 0; i < r; ++i)
				tmp.push_back(V[N-1-i]);

			sort(ALL(tmp));
			for (ll i = 0; i < th; ++i)
			{
				if (i >= tmp.size()) break;
				tmp[i] = max(tmp[i], 0ll);
			}

			res = max(res, accumulate(ALL(tmp), 0ll));
			
		}
	}

	std::cout << res << std::endl;
}
