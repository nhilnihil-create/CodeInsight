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
#define DEBUG(x) std::cerr << #x << " : " << (x) << std::endl;

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<ll> cnt(13, 0);
	cnt[0]++;
	ll N; cin >> N;
	REP(_, N)
	{
		ll a; cin >> a;
		cnt[a]++;
	}

	if (cnt[0] > 1)
	{
		std::cout << 0 << std::endl;
		return 0;
	}

	if (cnt[12] > 1)
	{
		std::cout << 0 << std::endl;
		return 0;
	}

	for (ll i = 1; i < 12; ++i)
	{
		if (cnt[i] > 2)
		{
			std::cout << 0 << std::endl;
			return 0;
		}
	}
	
	ll res{0};
	REP(bits, 1ll<<11)
	{
		vector<ll> c{0};
		
		if (cnt[12] == 1)
			c.push_back(12);
		
		for (ll ti = 1; ti < 12; ++ti)
		{
			ll tmp = cnt[ti];

			if (tmp == 2)
			{
				c.push_back(ti);
				c.push_back(ti+abs(12-ti)*2);
			}
			else if (tmp == 1)
			{
				if (bits & (1ll << (ti-1)))
					c.push_back(ti);
				else
					c.push_back(ti+abs(12-ti)*2);
			}
		}

		ll tmp{INF};

		ll M = c.size();
		REP(i, M)REP(j, M)
		{
			if (i == j) continue;
			ll d = abs(c[i] - c[j]);
			tmp = min(tmp, min(d, 24-d));
		}

		res = max(res, tmp);
	}

	std::cout << res << std::endl;
	return 0;
}
