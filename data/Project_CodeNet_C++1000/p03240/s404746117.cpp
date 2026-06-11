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
	ll n; cin >> n;
	vector<ll> x(n), y(n), h(n);
	REP(i, n) cin >> x[i] >> y[i] >> h[i];

	ll t;
	for (t = 0; t < n; ++t)
		if (h[t] > 0) break;

	auto f = [&x, &y, &h](ll X, ll Y, ll H, ll index)
			 {
				 return max(H - abs(X-x[index]) - abs(Y-y[index]), 0ll);
			 };
	

	ll X, Y, H;
	for (X = 0; X <= 100; ++X)
	{
		for (Y = 0; Y <= 100; ++Y)
		{
			H = h[t] + abs(x[t] - X) + abs(y[t] - Y);
			//std::cout << "X : " << X << std::endl;
			// std::cout << "Y : " << Y << std::endl;
			bool ok{true};
			for (ll i = 0; i < n; ++i)
			{
				if (h[i] != f(X, Y, H, i))
					ok = false;
			}

			if (ok && H >= 1) goto exit;
		}
	}

 exit:
	std::cout << X << " " << Y << " " << H << std::endl;
}
