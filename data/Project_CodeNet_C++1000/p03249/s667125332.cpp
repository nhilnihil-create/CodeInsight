
#include <map>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long int LL;
const int Max_N(100050);

namespace io
{
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	inline void flush (){fwrite (obuf, 1, oS - obuf, stdout);oS = obuf;}
	inline void putc (char x){*oS ++ = x;if (oS == oT) flush ();}
	template <class I>
	inline void gi (I &x) {for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;}
	template <class I>
	inline void print (I x){
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;while(x) qu[++ qr] = x % 10 + '0',  x /= 10;while (qr) putc (qu[qr--]);}
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io::gi;
using io::putc;
using io::print;

struct node
{
	int u;
	LL d;
};
int N, Head[Max_N], Next[Max_N], Size[Max_N];
node V[Max_N];
map<LL, int> S;

inline void Add_Edge(int s, int t)
{
	Next[t] = Head[s], Head[s] = t;
}

inline bool comp(const node &a, const node &b)
{
	return a.d > b.d;
}

LL Sum;
void dfs(int u, int dep)
{
	Sum += dep;
	for (int v = Head[u];v;v = Next[v])
		dfs(v, dep + 1);
}

void dfs2(int u)
{
	if (S[Sum] != u)
	{
		print(-1);
		exit(0);
	}
	for (int v = Head[u];v;v = Next[v])
		Sum += (N - Size[v]) - Size[v], dfs2(v), Sum -= (N - Size[v]) - Size[v];
}

int main()
{
	gi(N);
	for (int i = 1;i <= N;++i)
		gi(V[i].d), S[V[i].d] = V[i].u = i, Size[i] = 1;
	sort(V + 1, V + 1 + N, comp);
	for (int i = 1, u, fa;i < N;++i)
	{
		u = V[i].u;
		LL d = V[i].d - (N - Size[u]) + Size[u];
		if (d >= V[i].d || !(fa = S[d]))
		{
			print(-1);
			return 0;
		}
		Add_Edge(fa, u), Size[fa] += Size[u];
	}
	dfs(V[N].u, 0);
	dfs2(V[N].u);
	for (int u = 1;u <= N;++u)
		for (int v = Head[u];v;v = Next[v])
			print(u), putc(' '), print(v), putc('\n');
	return 0;
}