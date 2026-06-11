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

	ll h, n, w;

	for (h = 1; h <= 3500; ++h)
	{
		for (n = 1; n <= 3500; ++n)
		{
			ll A = N*h*n;
			ll B = 4*h*n - N*(n+h);
			if (B == 0) continue;
			if (A % B == 0)
			{
				w = A / B;
				if (1 <= w && w <= 3500)
				{
					goto exit;
				}
			}
		}
	}
 exit:
	std::cout << h << " " << n << " " << w << " " << std::endl;
}