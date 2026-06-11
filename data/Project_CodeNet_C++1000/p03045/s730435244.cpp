#include <cstdio>

int parent[111111], check[111111];

int Find(int x)
{
	if (x == parent[x])
		return x;
	else
		return parent[x] = Find(parent[x]);
}

int main(void)
{
	int n, m, i, x, y;

	scanf("%d %d" ,&n, &m);

	for (i = 1; i <= n; i++)
		parent[i] = i;

	while (m--)
	{
		scanf("%d %d %*d" ,&x, &y);

		x = Find(x);
		y = Find(y);

		if (x != y)
			parent[y] = x;
	}

	for (i = 1; i <= n; i++)
		check[Find(i)] = 1;

	int ans = 0;
	for (i = 1; i <= n; i++)
		ans += check[i];

	printf("%d" ,ans);
	return 0;
}