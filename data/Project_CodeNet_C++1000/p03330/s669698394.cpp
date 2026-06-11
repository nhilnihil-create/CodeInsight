#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, C;
ll D[35][35];
ll grid[510][510];
ll cost[3][35];

int main(int argc, char **argv)
{
	ll N, C; cin >> N >> C;
	for (ll i = 0; i < C; ++i) for (ll j = 0; j < C; ++j) cin >> D[i][j];
	for (ll i = 0; i < N; ++i) for (ll j = 0; j < N; ++j) cin >> grid[i][j], --grid[i][j];

	memset(cost, 0, sizeof(cost));
	for (ll x = 0; x < N; ++x)
	{
		for (ll y = 0; y < N; ++y)
		{
			for (ll c = 0; c < C; ++c)
				cost[(x+y)%3][c] += D[grid[x][y]][c];
		}
	}

	ll res{1ll<<60};
	for (ll c1 = 0; c1 < C; ++c1) // 0
	{
		for (ll c2 = 0; c2 < C; ++c2) // 1
		{
			if (c1 == c2) continue;
			for (ll c3 = 0; c3 < C; ++c3) // 2
			{
				if (c1 == c3 || c2 == c3) continue;
				ll tmp{0};
				tmp += cost[0][c1];
				tmp += cost[1][c2];
				tmp += cost[2][c3];
				res = min(res, tmp);
			}
		}
	}
	std::cout << res << std::endl;
}
