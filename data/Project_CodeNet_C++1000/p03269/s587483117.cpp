#include <bits/stdc++.h>
using namespace std;
#define maxn 100000
int L, n, m, ret, bit[30], a[30], tot = 1;

int read()
{
	int x = 0, k = 1;
	char c; c = getchar();
	while(c < '0' || c > '9') { if(c == '-') k = -1; c = getchar(); }
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * k; 
} 

struct edge
{
	int u, v, w;
}e[maxn];

int main()
{
	L = read(); int tem = L;
	while(tem) { n ++; a[n] = tem & 1; tem >>= 1; }
	bit[0] = 1; for(int i = 1; i <= n; i ++) bit[i] = bit[i - 1] << 1;
	for(int i = n - 2; i >= 0; i --)
	{
		int u = tot, v = ++ tot; 
		e[++ m].u = u, e[m].v = v, e[m].w = bit[i];
		e[++ m].u = u, e[m].v = v, e[m].w = 0;
	}
	ret += bit[n - 1];
	for(int i = n - 1; i; i --)
	{
		if(!a[i]) continue;
		e[++ m].u = 1, e[m].v = n - i + 1, e[m].w = ret;
		ret += bit[i - 1]; 
	}
	cout << tot << " " << m << endl;
	for(int i = 1; i <= m; i ++) 
		printf("%d %d %d\n", e[i].u, e[i].v, e[i].w);
	return 0;
}