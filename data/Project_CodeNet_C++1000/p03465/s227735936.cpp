#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2010;

int n, sum, a[MAXN];
bitset<MAXN * MAXN> f;

int main()
{
	scanf("%d", &n);
	f[0] = 1;
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		sum += a[i];
		f |= f << a[i];
	}
	for(int i = (sum + 1) / 2; i <= sum; ++i)
		if(f[i]) {printf("%d\n", i); break;}
	return 0;
}