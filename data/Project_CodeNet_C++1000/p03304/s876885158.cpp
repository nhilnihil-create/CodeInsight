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
	double n, m, d; cin >> n >> m >> d;


	std::cout << fixed << setprecision(10);
	if (d == 0)
	{
		std::cout << (m-1)*(1/n) << std::endl;
	}
	else
	{
		std::cout << 2*(n-d)/(n*n)*(m-1)  << std::endl;
	}
}