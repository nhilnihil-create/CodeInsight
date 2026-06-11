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

ll L, k;

int main(int argc, char **argv)
{
	cin >> L >> k;
	vector<ll> x(L), y(L), sx, sy;
	REP(i, L) cin >> x[i] >> y[i];
	sx = x;
	sy = y;

	sort(ALL(sx));
	sort(ALL(sy));

	ll res = (sx.back() - sx.front()) * (sy.back() - sy.front());

	for (ll xi = 0; xi < L-1; ++xi)
	{
		for (ll xj = xi + 1; xj < L; ++xj)
		{
			for (ll yi = 0; yi < L-1; ++yi)
			{
				for (ll yj = yi + 1; yj < L; ++yj)
				{
					ll x1 = sx[xi];
					ll x2 = sx[xj];
					ll y1 = sy[yi];
					ll y2 = sy[yj];

					ll cnt{0};
					REP(i, L)
						cnt += (x1 <= x[i] && x[i] <= x2) && (y1 <= y[i] && y[i] <= y2);

					if (cnt >= k)
						res = min(res, (x2-x1)*(y2-y1));
				}
			}
		}
	}

	std::cout << res << std::endl;
}
