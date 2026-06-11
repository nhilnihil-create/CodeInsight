/*
PROG: agc025c
LANG: C++11
    _____
  .'     '.
 /  0   0  \
|     ^     |
|  \     /  |
 \  '---'  /
  '._____.'
 */
#include <bits/stdc++.h>

using namespace std;

template<class T>
void readi(T &x)
{
	T input = 0;
	bool negative = false;
	char c = ' ';
	while (c < '-')
	{
		c = getchar();
	}
	if (c == '-')
	{
		negative = true;
		c = getchar();
	}
	while (c >= '0')
	{
		input = input * 10 + (c - '0');
		c = getchar();
	}
	if (negative)
	{
		input = -input;
	}
	x = input;
}
template<class T>
void printi(T output)
{
	if (output == 0)
	{
		putchar('0');
		return;
	}
	if (output < 0)
	{
		putchar('-');
		output = -output;
	}
	int aout[20];
	int ilen = 0;
	while(output)
	{
		aout[ilen] = ((output % 10));
		output /= 10;
		ilen++;
	}
	for (int i = ilen - 1; i >= 0; i--)
	{
		putchar(aout[i] + '0');
	}
	return;
}
template<class T>
void ckmin(T &a, T b)
{
	a = min(a, b);
}
template<class T>
void ckmax(T &a, T b)
{
	a = max(a, b);
}
long long randomize(long long mod)
{
	return ((1ll << 30) * rand() + (1ll << 15) * rand() + rand()) % mod;
}

#define MP make_pair
#define PB push_back
#define PF push_front
#define fi first
#define se second
#define debug(x) cerr << #x << " = " << x << endl;

const long double PI = 4.0 * atan(1.0);
const long double EPS = 1e-10;

#define MAGIC 347
#define SINF 10007
#define CO 1000007
#define INF 1000000007
#define BIG 1000000931
#define LARGE 1696969696967ll
#define GIANT 2564008813937411ll
#define LLINF 2696969696969696969ll
#define MAXN 200039

long long normalize(long long x, long long mod = INF)
{
	return (((x % mod) + mod) % mod);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
ll DIF = 100013;
pll coor[MAXN];
ll ans;
ll rtpref[MAXN], ltpref[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(0); 
	srand(time(0));
	//	cout << fixed << setprecision(10);	
	//	cerr << fixed << setprecision(10);
	if (fopen("agc025c.in", "r"))
	{	
		freopen ("agc025c.in", "r", stdin);
	//	freopen ("agc025c.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> coor[i].fi >> coor[i].se;
		coor[i].fi += DIF; coor[i].se += DIF;
	}
	coor[N] = MP(DIF, DIF);
	N++;
	for (int i = 0; i < N; i++)
	{
		ltpref[coor[i].se]++;
		rtpref[coor[i].fi]++;
	}
	for (int i = 1; i < MAXN; i++)
	{
		ltpref[i] += ltpref[i - 1];
		rtpref[i] += rtpref[i - 1];
	}
	for (int i = 0; i < MAXN - 2; i++)
	{
		//i..i+1
		int lt = ltpref[i], rt = rtpref[MAXN - 1] - rtpref[i];
//		for (int j = 0; j < N; j++)
//		{
//			if (coor[j].se <= i)
//			{
//				lt++;
//			}
//			if (coor[j].fi > i)
//			{
//				rt++;
//			}
//		}
		ans += min(lt, rt);
	}
	cout << 2 * ans << '\n';
	//	cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}
