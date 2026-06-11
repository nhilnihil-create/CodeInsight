#include <bits/stdc++.h>
using namespace std;

#define fo(i,s,t) for(int i = s; i <= t; ++ i)
#define fd(i,s,t) for(int i = s; i >= t; -- i)
#define bf(i,s) for(int i = head[s]; i; i = e[i].next)
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
#define VI vector<int>
#define sf scanf
#define pf printf
#define fp freopen
#define SZ(x) ((int)(x).size())
#ifdef MPS
#define D(x...) printf(x)
#else
#define D(x...)
#endif
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
const int inf = 1<<30;
const ll INF = 1ll<<60;
const db Inf = 1e20;
const db eps = 1e-9;

void gmax(int &a,int b){a = (a > b ? a : b);}
void gmin(int &a,int b){a = (a < b ? a : b);}

const int maxn = 1005;

int n, now, x[maxn], y[maxn];
char ans[maxn][32];

void calc(int v)
{
	++ now;
	fo(i,1,n)
	{
		if(abs(x[i]) > abs(y[i]))
		{
			if(x[i] > 0) x[i] -= v, ans[i][now] = 'R';
			else x[i] += v, ans[i][now] = 'L';
		}
		else
		{
			if(y[i] > 0) y[i] -= v, ans[i][now] = 'U';
			else y[i] += v, ans[i][now] = 'D';
		}
	}
}
int main()
{
	sf("%d",&n);
	int S = 0;
	fo(i,1,n) {sf("%d%d",&x[i],&y[i]); if((x[i] + y[i]) % 2 == 0) S = 1;}
	fd(i,30,0) calc((1<<i));  
	if(S) calc(1);
	fo(i,1,n) if(x[i] || y[i]) return 0 * pf("-1\n");
	if(S) pf("32\n1"); else pf("31\n");
	if(S) fo(i,0,30) pf(" %d", (1<<i)); else fo(i,0,30) pf("%d ",(1<<i));
	puts("");
	fo(i,1,n) {fd(j,now,1) pf("%c",ans[i][j]); puts("");}
	return 0;
}