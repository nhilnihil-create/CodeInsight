#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

int main(int argc, char **argv)
{
	ll N, K; cin >> N >> K;
	vector<ll> A(N); REP(i, N) cin >> A[i];
	vector<ll> sum;

	REP(i, N)
	{
		ll tmp{0};
		for (ll j = i; j < N; ++j)
		{
			tmp += A[j];
			sum.push_back(tmp);
		}
	}

	ll res{0};

	for (ll bit = 40; bit >= 0; --bit)
	{
		ll tmp = res | (1ll<<bit);

		ll cnt{0};
		for (auto &e : sum)
		{
			if ((e & tmp) == tmp)
				++cnt;
		}
		if (cnt >= K)
			res = tmp;
	}

	std::cout << res << std::endl;
}
