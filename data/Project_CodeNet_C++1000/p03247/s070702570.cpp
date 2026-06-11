/*
    _____
  .'     '.
 /  0   0  \
|     ^     |
|  \     /  |
 \  '---'  /
  '._____.'
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

struct chash
{
	int operator()(int x) const
	{
		x ^= (x >> 20) ^ (x >> 12);
		return x ^ (x >> 7) ^ (x >> 4);
	}
};

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename U> using hashtable = gp_hash_table<T, U, chash>;
random_device(rd);
mt19937 rng(rd());

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
template<class T, class U>
T nmod(T &x, U mod)
{
	if (x >= mod) x -= mod;
}
template<class T>
T gcd(T a, T b)
{
	return (b ? gcd(b, a % b) : a);
}
template<class T>
T randomize(T mod)
{
	return (uniform_int_distribution<T>(0, mod - 1))(rng);
}

#define y0 ___y0
#define y1 ___y1
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
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
#define MAXN 1013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;

int N, M;
pll coor[MAXN];
ll ans[MAXN];
int dir[MAXN][MAXN];
ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
string ch = "RULD";

bool ok(ll x, ll y)
{
	return ((x % 2 == 0) && (y % 2 == 0) && (((x + y) % 4 == 2) || ((x + y) % 4 == -2)));
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	// cout << fixed << setprecision(10);
	// cerr << fixed << setprecision(10);
	// freopen ("file.in", "r", stdin);
	// freopen ("file.out", "w", stdout);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> coor[i].fi >> coor[i].se;
	}
	for (int i = 1; i < N; i++)
	{
		if ((coor[i].fi + coor[i].se + coor[0].fi + coor[0].se) % 2)
		{
			cout << "-1\n";
			return 0;
		}
	}
	M = 35;
	if ((coor[0].fi + coor[0].se) % 2 == 0)
	{
		ans[35] = 1;
		for (int i = 0; i < N; i++)
		{
			coor[i].fi--;
			dir[i][35] = 0;
		}
		M++;
	}
	for (int i = 0; i <= 33; i++)
	{
		// cerr << "work " << i << endl;
		ans[i] = (1ll << i);
		for (int j = 0; j < N; j++)
		{
			ll x, y;
			for (int k = 0; k < 4; k++)
			{
				x = coor[j].fi - dx[k];
				y = coor[j].se - dy[k];
				if (!ok(x, y))
				{
					continue;
				}
				dir[j][i] = k;
				coor[j] = {x, y};
				break;
			}
		}
		for (int j = 0; j < N; j++)
		{
			// cerr << "from " << coor[j].fi << ',' << coor[j].se << " to ";
			coor[j].fi /= 2;
			coor[j].se /= 2;
			// cerr << coor[j].fi << ',' << coor[j].se << endl;
		}
	}
	ans[34] = (1ll << 34);
	for (int j = 0; j < N; j++)
	{
		ll x, y;
		for (int k = 0; k < 4; k++)
		{
			x = coor[j].fi - dx[k];
			y = coor[j].se - dy[k];
			// cerr << "help " << x << ' ' << y << endl;
			if (x != 0 || y != 0)
			{
				continue;
			}
			dir[j][34] = k;
			coor[j] = {x, y};
			break;
		}
	}
	cout << M << endl;
	bool flag = false;
	for (int i = 0; i < M; i++)
	{
		if (ans[i] == 0)
		{
			continue;
		}
		if (flag) cout << ' ';
		cout << ans[i];
		flag = true;
	}
	cout << '\n';
	for (int i = 0; i < N; i++)
	{
		ll x = 0, y = 0;
		for (int j = 0; j < M; j++)
		{
			if (ans[j] == 0)
			{
				continue;
			}
			x += dx[dir[i][j]] * ans[j]; y += dy[dir[i][j]] * ans[j];
			cout << ch[dir[i][j]];
		}
		// assert(x == coor[i].fi && y == coor[i].se);
		// cerr << " finish " << x << ' ' << y << endl;
		cout << '\n';
	}
	// cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}
