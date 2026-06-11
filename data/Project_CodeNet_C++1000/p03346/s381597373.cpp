#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

int main(int argc, char **argv)
{
	ll N; cin >> N;
	vector<ll> P(N); REP(i, N) cin >> P[i];
	vector<ll> Q(N);

	REP(i, N)
	{
		Q[P[i]-1] = i;
	}

	ll res{1}, tmp{1};
	REP(i, N-1)
	{
		if (Q[i] < Q[i+1])
		{
			++tmp;
		}
		else
		{
			tmp = 1;
		}
		res = max(res, tmp);
	}

	std::cout << N - res << std::endl;
}