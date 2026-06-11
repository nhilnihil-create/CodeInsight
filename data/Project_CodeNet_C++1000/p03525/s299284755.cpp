#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

ll N;
ll D[100];
int main(int argc, char **argv)
{
	cin >> N;
	D[0] = 0;
	REP(i, N)
		cin >> D[i+1];
	++N;

	vector<ll> cnt(13, 0);
	REP(i, N)
		++cnt[D[i]];

	REP(i, 13)
	{
		if (i == 0 || i == 12)
		{
			if (cnt[i] >= 2)
			{
				std::cout << 0 << std::endl;
				return 0;
			}
		}
		else if (cnt[i] >= 3)
		{
			std::cout << 0 << std::endl;
			return 0;
		}
	}
	
	ll res{0};
	for (ll time = 0; time < (1ll<<11); ++time)
	{
		vector<ll> tmp;

		if (cnt[0])
			tmp.push_back(0);
		if (cnt[12])
			tmp.push_back(12);

		for (ll i = 1; i < 12; ++i)
		{
			if (cnt[i] == 2)
			{
				tmp.push_back(i);
				tmp.push_back(24-i);
			}
			else if (cnt[i] == 1)
			{
				if (time & (1ll << (i-1)))
					tmp.push_back(24-i);
				else
					tmp.push_back(i);
			}
		}

		ll tmp2{INF};
		for (ll i = 0; i < N-1; ++i)
			for (ll j = i + 1; j < N; ++j)
			{
				ll t = abs(tmp[i] - tmp[j]);
				tmp2 = min(tmp2, min(24-t, t));
			}

		res = max(res, tmp2);
	}


	std::cout << res << std::endl;
}
