#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

pair<int, int> pp[99999];
int v[99999];

int main(void)
{
	int h, w, d, q, i, j, a, L, R;

	scanf("%d %d %d" ,&h, &w, &d);
	for (i = 1; i <= h; i++)
		for (j = 1; j <= w; j++)
		{
			scanf("%d" ,&a);
			pp[a] = make_pair(i, j);
		}

	for (i = d + 1; i <= h * w; i++)
		v[i] = v[i - d] + abs(pp[i - d].first - pp[i].first) + abs(pp[i - d].second - pp[i].second);

	scanf("%d" ,&q);
	while (q--)
	{
		scanf("%d %d" ,&L, &R);

		printf("%d\n" ,v[R] - v[L]);
	}
	return 0;
}