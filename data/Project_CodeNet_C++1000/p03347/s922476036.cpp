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
	vector<ll> A(N); REP(i, N) cin >> A[i];

	ll res{-1};

	if (A.front() != 0)
	{
		std::cout << res << std::endl;
		return 0;
	}

	REP(i, N-1)
	{
		if (A[i] == 0 && A[i+1] > 1)
		{
			std::cout << res << std::endl;
			return 0;
		}
	}

	res = 0;

	reverse(ALL(A));
	for (ll i = 0; i < N; )
	{
		ll j = i + 1;
		if (A[i] != 0)
		{
			res += A[i];
			while (j < N && A[j] != 0)
			{
				if (A[j-1] == A[j]+1)
				{
					++j;
				}
				else if (A[j-1] <= A[j])
				{
					res += A[j];
					++j;
				}
				else
				{
					std::cout << -1 << std::endl;
					return 0;
				}
			}
		}
		i = j;
	}

	std::cout << res << std::endl;
}
