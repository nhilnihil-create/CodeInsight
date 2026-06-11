#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()


bool to[110][110];

int main(int argc, char **argv)
{
	ll N; cin >> N;
	memset(to, 0, sizeof to);
	ll NN = N;

	vector<vector<ll>> t;
	if (N&1)
	{
		vector<ll> tmp{N};
		t.push_back(tmp);
		--N;
	}

	ll l{1}, r{N};

	while (r - l >= 1)
	{
		vector<ll> tmp{l, r};
		t.push_back(tmp);
		++l;
		--r;
	}

	// std::cout << "t : " << t.size() << std::endl;

	ll M = t.size();

	REP(i, M)
	{
		vector<ll> &v1 = t[i];
		vector<ll> &v2 = t[(i+1)%M];

		for (auto &e : v1)
		{
			for (auto &e1 : v2)
			{
				to[e][e1] = true;
			}
		}
	}


	ll res{0};
	for (ll i = 1; i <= NN; ++i)
	{
		for (ll k = 1; k <= NN; ++k)
		{
			if (to[i][k])
			{
				++res;
				to[k][i] = false;
			}
		}
	}

	std::cout << res << std::endl;
	for (ll i = 1; i <= NN; ++i)
	{
		for (ll k = 1; k <= NN; ++k)
		{
			if (to[i][k])
			{
				std::cout << i << " " << k << std::endl;
			}
		}
	}
}
