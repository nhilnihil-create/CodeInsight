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
typedef pair<int, int> pii;
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
int a[maxn];
ul s[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	ul Ans = LLONG_MAX;
	for(int i = 1; i <= n; i ++)
		s[i] = s[i - 1] + a[i];
	for(int i = 1; i <= n; i ++)
	{
		ul res = (ul)i * m;
		int cur = n - 2 * i;
		cur = max(cur, 0);
		res += 5 * (s[n] - s[cur]);
		for(int j = 7; cur; j += 2)
		{
			int tmp = cur - i;
			tmp = max(tmp, 0);
			res += j * (s[cur] - s[tmp]);
			cur = tmp;
		}
		Ans = min(Ans, res);
	}
	Ans += (ul)n * m;
	cout << Ans << endl;
	return 0;
}
