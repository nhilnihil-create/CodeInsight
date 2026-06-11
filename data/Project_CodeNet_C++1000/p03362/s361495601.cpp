#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

vector<bool> sieve(ll N)
{
	vector<bool> isp(N+1, true);

	isp[0] = false;
	isp[1] = false;
	for (ll i = 2; i*i <= N; ++i)
	{
		if (isp[i]) for (ll j = i*i; j <= N; j+=i) isp[j] = false;
	}
	return isp;
}
int main(int argc, char **argv)
{
	ll N; cin >> N;
	vector<bool> isp = sieve(60000);

	--N;
	std::cout << 2 << " ";
	for(ll i = 1; i < 30000; ++i)
	{
		if (isp[5*i+1])
		{
			std::cout << 5*i+1;
			--N;
			if (N == 0) break;
			else
				std::cout << " ";
		}
	}
	std::cout << std::endl;

}
