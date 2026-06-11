#include <stdio.h>
#include <queue>
using namespace std;

#define INF 1e9

queue<int> Q;
char a[1111];
int d[1111][1111], dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

int main(void)
{
	int h, w, i, j;

	scanf("%d %d" ,&h, &w);
	for (i = 1; i <= h; i++)
	{
		scanf("%s" ,&a[1]);
		for (j = 1; j <= w; j++)
		{
			d[i][j] = INF;
			if (a[j] == '#')
			{
				Q.push(i);
				Q.push(j);
				d[i][j] = 0;
			}
		}
	}

	while (!Q.empty())
	{
		int yy = Q.front(); Q.pop();
		int xx = Q.front(); Q.pop();

		for (i = 0; i < 4; i++)
		{
			int ty = yy + dy[i];
			int tx = xx + dx[i];

			if (ty >= 1 && ty <= h && tx >= 1 && tx <= w && d[ty][tx] == INF)
			{
				d[ty][tx] = d[yy][xx] + 1;
				Q.push(ty);
				Q.push(tx);
			}
		}
	}

	int ans = 0;

	for (i = 1; i <= h; i++)
		for (j = 1; j <= w; j++)
			if (ans < d[i][j])
				ans = d[i][j];

	printf("%d" ,ans);
	return 0;
}