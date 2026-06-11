#include <cstdio>

int n = 0, m = 0;
int u[66], v[66], c[66];
int main()
{
	int l; scanf("%d", &l);
	int C = l;
	while(l) l >>= 1, n++;
	l = C;
	for(int i = 1; i < n; i++) 
	{
		++m;
		u[m] = i; v[m] = i + 1; c[m] = 1 << (n - i - 1);
		++m;
		u[m] = i; v[m] = i + 1; c[m] = 0;
	}
	int s = 1 << (n - 1); 
	for(int i = n - 2; i >= 0; i--)
	{
		if((l >> i) & 1)
		{
			m++;
			u[m] = 1; v[m] = n - i; c[m] = s;
			s += 1 << i;
		}
	}
	printf("%d %d\n", n, m);
	for(int i = 1; i <= m; i++) printf("%d %d %d\n", u[i], v[i], c[i]);
	return 0;
}