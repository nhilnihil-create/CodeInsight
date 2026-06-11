#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>

using namespace std;
typedef long long ll;

int main()
{
	int N, C;
	scanf("%d%d", &N, &C);

	int D[30][30];
	for (int i = 0; i < C; i++)
		for (int j = 0; j < C; j++)
			scanf("%d", &D[i][j]);

	int c[500][500];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			scanf("%d", &c[i][j]);
			c[i][j]--;
		}

	ll cost[3][30];
	for (int i = 0; i < 3; i++)
		fill(cost[i], cost[i] + C, 0);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			int pos = (i + j + 2) % 3;
			for (int k = 0; k < C; k++)
				cost[pos][k] += (ll)D[c[i][j]][k];
		}

	ll res = numeric_limits<ll>::max();
	for (int i = 0; i < C; i++)
		for (int j = 0; j < C; j++) {
			if (j == i)
				continue;
			for (int k = 0; k < C; k++) {
				if (k == i || k == j)
					continue;
				res = min(res, cost[0][i] + cost[1][j] + cost[2][k]);
			}
		}

	printf("%lld\n", res);

	return 0;
}
