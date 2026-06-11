#include<bits/stdc++.h>
using namespace std;

int L, now, res, lg2[1000010];
int n, cnt, from[110], to[110], val[110];

int main()
{
	lg2[1] = 0;
	for(int i = 2; i < 1000010; ++i) lg2[i] = lg2[i >> 1] + 1;
	scanf("%d", &L); --L; n = lg2[L] + 1;
	now = lg2[L], res = (1 << now) - 1;
	for(int i = 1; i <= now; ++i)
	{
		from[++cnt] = i, to[cnt] = i + 1, val[cnt] = 1 << (i - 1);
		from[++cnt] = i, to[cnt] = i + 1, val[cnt] = 0;
	}
	if(L == (1 << (now + 1)) - 1)
	{
		from[++cnt] = n, to[cnt] = n + 1, val[cnt] = 1 << (n - 1);
		from[++cnt] = n, to[cnt] = n + 1, val[cnt] = 0; ++n;
	}
	else
	{
		now = lg2[L - res];
		while(res < L)
		{
			from[++cnt] = now + 1, to[cnt] = n, val[cnt] = res + 1;
			res = res + (1 << now), now = lg2[L - res];
		}
	}
	printf("%d %d\n", n, cnt);
	for(int i = 1; i <= cnt; ++i)
		printf("%d %d %d\n", from[i], to[i], val[i]);
	return 0;
}