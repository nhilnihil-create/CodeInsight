#include<cstdio>
#include<iostream>
using namespace std;
const int N = 99999;
int n, m, d, q;
int X[N], Y[N], f[N];
int Mabs(int x)
{
	return x<0?-x:x;
}
int main()
{
	scanf("%d%d%d", &n, &m, &d);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			int x;
			scanf("%d", &x);
			X[x] = i;
			Y[x] = j;
		}
	for(int i = d + 1; i <= n*m; i++)
		f[i] = f[i-d] + Mabs(X[i]-X[i-d]) + Mabs(Y[i]-Y[i-d]);
	scanf("%d", &q);
	for(int i = 1; i <= q; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", f[y] - f[x]);
	}
	return 0;
}