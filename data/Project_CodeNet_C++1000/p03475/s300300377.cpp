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
	vector<ll> C(N-1), S(N-1), F(N-1);
	REP(i, N-1) cin >> C[i] >> S[i] >> F[i];

	REP(i, N)
	{
		ll t{0};
		FOR(k, i, N-1)
		{
			if (t <= S[k]) t = S[k];
			else if (t % F[k] != 0) t += F[k] - t%F[k];
			t += C[k];
		}
		std::cout << t << std::endl;
	}
}
