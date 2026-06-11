#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#define priority_queue __gnu_pbds::priority_queue
typedef long long LL;
typedef long double LD;
typedef unsigned int ui;
typedef unsigned long long ul;
#define ri register int
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define mid ((l + r) >> 1)
#define ls (i << 1)
#define rs (i << 1 | 1)
using namespace std;
typedef pair<int*, int> pii;
typedef pair<LL, LL> pll;
typedef pair<int, LL> pil;
typedef pair<LL, int> pli;
#define adde(x, y) { e[++z].v = y; e[z].nxt = h[x]; h[x] = &e[z]; }
#define addrev(u, v) { adde(u, v); adde(v, u); }
#define ae(x) for(node *p = h[x]; p; p = p->nxt)
#define FO(x) { freopen("#x.in", "r", stdin); freopen("#x.out", "w", stdout); }
inline int read() // ret >= 0
{
	int ret = 0; char ch = getchar();
	while(ch < '0' || ch > '9')
		ch = getchar();
	do {
		ret = ret * 10 + ch - '0';
		ch = getchar();
	} while('0' <= ch && ch <= '9');
	return ret;
}
inline void write(int x) // x >= 0
{
	if(x < 10)
	{
		putchar(x + '0');
		return ;
	}
	write(x / 10);
	putchar(x % 10 + '0');
}
#define maxn 200100
int n, m;
bool f[maxn];
struct node
{
	int v;
	node *nxt;
} e[2 * maxn], *h[maxn];
int z;
int t[maxn][2];
class cmp
{
	public: bool operator () (pii a, pii b)
	{
		return min(a.first[0], a.first[1]) > min(b.first[0], b.first[1]);
	}
};
priority_queue<pii, cmp> pq;
bool vis[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 1; i <= n; i ++)
		f[i] = s[i - 1] == 'A';
	for(int i = 0, u, v; i < m; i ++)
	{
		cin >> u >> v;
		addrev(u, v);
		t[u][f[v]] ++;
		t[v][f[u]] ++;
	}
	for(int i = 1; i <= n; i ++)
		pq.push(pii(t[i], i));
	while(!pq.empty())
	{
		int x = pq.top().second;
		pq.pop();
		if(vis[x])
			continue;
		vis[x] = true;
		if(min(t[x][0], t[x][1]) != 0)
			break;
		ae(x)
		{
			t[p->v][f[x]] --;
			if(!vis[p->v])
			{
				pq.push(pii(t[p->v], p->v));
			}
		}
	}
	cout << (pq.empty() ? "No" : "Yes") << endl;
	return 0;
}
