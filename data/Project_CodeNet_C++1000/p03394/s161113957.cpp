#include <bits/stdc++.h>
using namespace std;
const int maxa = 30000;
const int maxn = 30000 + 10;
int n;
bool f[maxn];
int main()
{
	for(int i = 2; i <= maxa; i += 2) f[i] = 1;
	for(int i = 3; i <= maxa; i += 3) f[i] = 1;
	scanf("%d", &n);
	if(n == 3)
	{
		puts("2 5 63");
		return 0;
	}
	if(n & 1)
	{
		printf("%d ", 30000);
		--n;
	}
	for(int i = 1; n; ++i)
	{
		if(f[i]) 
		{
			printf("%d ", i);
			--n;
			if(i != maxa - i) printf("%d ", maxa - i);
			else printf("%d ", maxa);
			--n;
		}
	}
	return 0;
}