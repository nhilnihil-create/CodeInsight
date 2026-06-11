#include <bits/stdc++.h>

int N = 1e6, SZ = 320, INF = 1 << 29;
long long LINF = (1LL << 60), mod = 1e9 + 7;
const long double eps = 1e-8, PI = acos(-1.0);

#define lowbit(x) (x & (-(x)))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef complex<double> cpx;

char READ_DATA;
int SIGNAL_INPUT;
inline int dcmp(double x, double y = 0.0)
{
	return abs(x - y) < eps;
}
template <typename Type>
inline Type ru(Type &v)
{
	SIGNAL_INPUT = 1;
	while ((READ_DATA = getchar()) < '0' || READ_DATA > '9')
		if (READ_DATA == '-')
			SIGNAL_INPUT = -1;
		else if (READ_DATA == EOF)
			return EOF;
	v = READ_DATA - '0';
	while ((READ_DATA = getchar()) >= '0' && READ_DATA <= '9')
		v = v * 10 + READ_DATA - '0';
	v *= SIGNAL_INPUT;
	return v;
}
inline ll modru(ll &v)
{
	ll p = 0;
	SIGNAL_INPUT = 1;
	while ((READ_DATA = getchar()) < '0' || READ_DATA > '9')
		if (READ_DATA == '-')
			SIGNAL_INPUT = -1;
		else if (READ_DATA == EOF)
			return EOF;
	p = v = READ_DATA - '0';
	while ((READ_DATA = getchar()) >= '0' && READ_DATA <= '9')
	{
		v = (v * 10 + READ_DATA - '0') % mod;
		p = (p * 10 + READ_DATA - '0') % (mod - 1);
	}
	v *= SIGNAL_INPUT;
	return p;
}
template <typename A, typename B>
inline int ru(A &x, B &y)
{
	if (ru(x) == EOF)
		return EOF;
	ru(y);
	return 2;
}
template <typename A, typename B, typename C>
inline int ru(A &x, B &y, C &z)
{
	if (ru(x) == EOF)
		return EOF;
	ru(y);
	ru(z);
	return 3;
}
template <typename A, typename B, typename C, typename D>
inline int ru(A &x, B &y, C &z, D &w)
{
	if (ru(x) == EOF)
		return EOF;
	ru(y);
	ru(z);
	ru(w);
	return 4;
}
inline ll gcd(ll a, ll b)
{
	while (b)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}
inline ll ss(ll a, ll b)
{
	ll ans = 1;
	while (b)
	{
		if (b & 1)
			(ans *= a) %= mod;
		(a *= a) %= mod;
		b >>= 1;
	}
	return ans;
}
template <typename Type>
void brc(Type *a, int n)
{
	int k;
	for (int i = 1, j = n / 2; i < n - 1; i++)
	{
		if (i < j)
			swap(a[i], a[j]);

		k = n >> 1;
		while (j >= k)
		{
			j ^= k;
			k >>= 1;
		}
		if (j < k)
			j ^= k;
	}
}
void fft(cpx *a, int n, int inv = 1)
{
	cpx u, t;
	brc(a, n);
	for (int h = 2; h <= n; h <<= 1)
	{
		cpx wn(cos(inv * 2.0 * PI / h), sin(inv * 2.0 * PI / h));
		for (int j = 0; j < n; j += h)
		{
			cpx w(1, 0);
			for (int k = j; k < j + (h >> 1); k++)
			{
				u = a[k];
				t = w * a[k + (h >> 1)];
				a[k] = u + t;
				a[k + (h >> 1)] = u - t;
				w *= wn;
			}
		}
	}
	if (inv == -1)
		for (int i = 0; i < n; i++)
		{
			a[i] /= n;
		}
}
void ntt(ll *a, int n, int inv = 1)
{
	ll u, t;
	brc(a, n);
	for (int h = 2; h <= n; h <<= 1)
	{
		ll wn = ss(3, (mod - 1) / h);
		if (inv == -1)
			wn = ss(wn, mod - 2);
		for (int j = 0; j < n; j += h)
		{
			ll w = 1;
			for (int k = j; k < j + (h >> 1); k++)
			{
				u = a[k];
				t = w * a[k + (h >> 1)] % mod;
				a[k] = (u + t) % mod;
				a[k + (h >> 1)] = (u - t + mod) % mod;
				(w *= wn) %= mod;
			}
		}
	}
	if (inv == -1)
	{
		ll tmp = ss(n, mod - 2);
		for (int i = 0; i < n; i++)
			(a[i] *= tmp) %= mod;
	}
}
struct Edge
{
	int u, v, nxt;
	ll w;
	Edge(int _u = 0, int _v = 0, ll _w = 0, int _nxt = -1)
	{
		u = _u;
		v = _v;
		w = _w;
		nxt = _nxt;
	}

	int operator<(const Edge &b) const
	{
		return u < b.u;
	}
};

const int maxn = 1e6 + 5;
/*------------------------------------------------------------------------yah------------------------------------------------------------------------*/

int n,id[maxn],cnt[maxn];
vector<pii> ans;
ll d[maxn],dis[maxn];

map<ll,vector<int> > f;
int cmp(const int &i,const int &j)
{
	return d[i]>d[j];
}

int main()
{
	ru(n);
	for (int i = 1; i < n+1; i++)
	{
		ru(d[i]);
		f[d[i]].push_back(i);
		id[i]=i;
		cnt[i]=1;
	}
	sort(id+1,id+n+1,cmp);

	int ok=1;
	for (int i = 1; i < n; i++)
	{
		vector<int> &tmp = f[d[id[i]]+2*cnt[id[i]]-n];
		//printf("%d %d\n",id[i],cnt[id[i]]);
		if(!tmp.empty())
		{
			int v=tmp.back();
			ans.push_back(pii(id[i],v));
			cnt[v]+=cnt[id[i]];
			dis[v]+=dis[id[i]]+cnt[id[i]];
		}
		else
		{
			ok=0;
			break;
		}
		
	}
	if(dis[id[n]]!=d[id[n]])
		ok=0;

	if(ok)
	{
		for (int i = 0; i < n-1; i++)
		{
			printf("%d %d\n",ans[i].first,ans[i].second);
		}
	}
	else
	{
		printf("-1");
	}
	
}