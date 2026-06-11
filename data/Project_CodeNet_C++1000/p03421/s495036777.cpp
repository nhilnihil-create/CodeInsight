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
#define MPS
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
const int inf = 1<<30;
const ll INF = 1ll<<60;
const db Inf = 1e20;
const db eps = 1e-9;

void gmax(int &a,int b){a = (a > b ? a : b);}
void gmin(int &a,int b){a = (a < b ? a : b);}

const int maxn = 300050;

int n, a, b, v[maxn];

int main()
{
	cin >> n >> a >> b;
	if(a + b - 1 > n) return 0 * pf("-1\n");
	if(1ll * n > 1ll * a * b) return 0 * pf("-1\n");
	fo(i,1,n) v[i] = i;
	a = n - a;
	for(int i = 1; a && i <= n; i += b)
	{
		a = min(n - i, a);
		if(a >= b-1) {reverse(v + i, v + i + b); a -= b - 1;}
		else {reverse(v + i, v + i + a + 1); a = 0;}
	}
	fo(i,1,n) pf("%d ", v[i]);
	return 0;
}