#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, C;
ll diff[35][35];
ll c[510][510];
ll cost[3][35];

int main(int argc, char **argv)
{
	cin >> N >> C;
	for (ll c1 = 0; c1 < C; ++c1)
		for (ll c2 = 0; c2 < C; ++c2)
			cin >> diff[c1][c2];
	for (ll n1 = 0; n1 < N; ++n1)
		for (ll n2 = 0; n2 < N; ++n2)
			cin >> c[n1][n2], --c[n1][n2];

	memset(cost, 0, sizeof(cost));
	for (ll n1 = 0; n1 < N; ++n1)
		for (ll n2 = 0; n2 < N; ++n2)
			for (ll ci = 0; ci < C; ++ci)
				cost[(n1+n2)%3][ci] += diff[(c[n1][n2])][ci];

	// std::cout << "----------"<< std::endl;
	// for (ll i = 0; i < 3; ++i)
	// {
	// 	std::cout << i << " : ";
	// 	for (ll ci = 0; ci < C; ++ci)
	// 		std::cout << cost[i][ci]<< " ";
	// 	std::cout << std::endl;
	// }
	// std::cout << "----------"<< std::endl;

	ll res{1ll<<60};
	for (ll c1 = 0; c1 < C; ++c1) // 0
	{
		for (ll c2 = 0; c2 < C; ++c2) // 1
		{
			if (c1 == c2) continue;
			for (ll c3 = 0; c3 < C; ++c3) // 2
			{
				if (c1 == c3 || c2 == c3) continue;
				ll tmp {0};
				tmp += cost[0][c1];
				tmp += cost[1][c2];
				tmp += cost[2][c3];
				res = min(res, tmp);
			}
		}
	}

	std::cout << res << std::endl;
}
