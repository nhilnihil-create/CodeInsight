#include <bits/stdc++.h>
#define DEBUG fprintf(stderr, "Passing [%s] line %d\n", __FUNCTION__, __LINE__)
#define File(x) freopen(x".in","r",stdin); freopen(x".out","w",stdout)

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <int, PII> PIII;

template <typename T>
inline T gi()
{
	T f = 1, x = 0; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return f * x;
}

const int INF = 0x3f3f3f3f, N = 100003, M = N << 1;

int n, m;
int dp[N];
int tot, head[N], ver[M], nxt[M], in[N];

inline void add(int u, int v)
{
	ver[++tot] = v, nxt[tot] = head[u], head[u] = tot;
}

int main()
{
	//File("");
	n = gi <int> (), m = gi <int> ();
	for (int i = 1; i <= m; i+=1) {int u = gi <int> (), v = gi <int> (); add(u, v), ++in[v];}
	queue <int> q;
	for (int i = 1; i <= n; i+=1) if (!in[i]) q.push(i);
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (int i = head[u]; i; i = nxt[i])
		{
			int v = ver[i];
			dp[v] = max(dp[v], dp[u] + 1);
			if (!(--in[v])) q.push(v);
		}
	}
	int mx = 0;
	for (int i = 1; i <= n; i+=1) mx = max(mx, dp[i]);
	printf("%d\n", mx);
	return 0;
}
