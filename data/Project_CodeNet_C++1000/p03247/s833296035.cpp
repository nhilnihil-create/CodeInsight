#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
const int N = 1005;
int n, X[N], Y[N], len[50];
char ans[50];
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
	return x * f;
}
int Abs(int x) {return x >= 0 ? x : - x;}
signed main()
{
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i ++) X[i] = read(), Y[i] = read();
	int tmp = Abs(X[1] + Y[1]) & 1;
	for(int i = 1; i <= n; i ++) if((Abs(X[i] + Y[i]) & 1) != tmp) {puts("-1"); return 0;}
	printf("%lld\n", 32 - tmp); int N = 1; len[1] = 1;
	if(tmp) for(int i = 1; i <= 30; i ++) len[++ N] = (1 << i);
	else for(int i = 0; i <= 30; i ++) len[++ N] = (1 << i);
	for(int i = 1; i <= 32 - tmp; i ++) printf("%lld ", len[i]); puts("");
	for(int i = 1; i <= n; i ++)
	{
		int nx = 0, ny = 0;
		for(int j = N; j >= 1; j --)
		{
			int x = X[i] - nx, y = Y[i] - ny;
			if(Abs(x) > Abs(y))
			{
				if(x > 0) nx += len[j], ans[j] = 'R';
				else nx -= len[j], ans[j] = 'L';
			}
			else
			{
				if(y > 0) ny += len[j], ans[j] = 'U';
				else ny -= len[j], ans[j] = 'D';
			}
		}
		printf("%s\n", ans + 1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
