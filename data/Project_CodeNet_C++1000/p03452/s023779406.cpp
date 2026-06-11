#define ll long long
#define R register
#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 2e5 + 5;
int n, m, l, r, dis, fa[maxn], d[maxn], h[maxn];
 
inline int get(int x, int ans = 0)
{
    if(x == fa[x]) return d[x];
    return d[x] + get(fa[x]);
}
 
inline int find(int x)
{
	if(x == fa[x]) return x;
    return find(fa[x]);
}
 
int main()
{
	for (R int i = 0; i < maxn; ++i) fa[i] = i, h[i] = 1;
	scanf("%d%d", &n, &m);
	for (R int i = 1; i <= m; ++i)
	{
		scanf("%d%d%d", &l, &r, &dis);
		int a = find(l), b = find(r);
		if(a != b) 
		{
		    if(h[a] > h[b]) fa[b] = a, d[b] = get(l) - get(r) + dis;
		    else if(h[a] < h[b]) fa[a] = b, d[a] = get(r) - get(l) - dis;
		    else fa[a] = b, d[a] = get(r) - get(l) -dis, ++h[b];
		}
		else if(get(r) - get(l) != dis) 
		    return puts("No"), 0;
	}
	return puts("Yes"), 0;
}