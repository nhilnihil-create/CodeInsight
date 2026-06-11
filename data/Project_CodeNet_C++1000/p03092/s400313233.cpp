#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int maxN = 5005;

int n;
int cnt[maxN + 1], a[maxN + 1], pos[maxN + 1];
LL A, B;
LL f[maxN + 1][maxN + 1];

int main()
{
	scanf("%d", &n);
	scanf("%lld %lld", &A, &B);
	for(int i = 1; i <= n; i++) 
	{
		scanf("%d", &a[i]);
		pos[ a[i] ] = i;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = a[i] + 1; j <= n; j++)
			if(pos[j] <= i) cnt[j] ++;
		for(int j = 1; j <= n; j++)
			if(pos[j] <= i)
			{
				if(!cnt[j]) f[i][j] = f[i][j - 1];
				else f[i][j] = min(f[i][j - 1] + A, f[ pos[j] - 1 ][j] + B * cnt[j]);
			}
			else f[i][j] = f[i][j - 1];
	}
	printf("%lld", f[n][n]);
	return 0;
}
