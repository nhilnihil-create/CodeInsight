#include <map>
#include <set>
#include <ctime>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <bitset>
#include <cstdio>
#include <cctype>
#include <string>
#include <numeric>
#include <cstring>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std ;
#define rep(i, a, b) for (register int i = (a); i <= (b); ++i)
#define per(i, a, b) for (register int i = (a); i >= (b); --i)
#define loop(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define cont(i, x) for (register int i = head[x]; i; i = edge[i].nex)
#define clr(a) memset(a, 0, sizeof(a))
#define ass(a, cnt) memset(a, cnt, sizeof(a))
#define cop(a, b) memcpy(a, b, sizeof(a))
#define lowbit(x) ((x) & (-(x)))
#define all(x) x.begin(), x.end()
#define SC(t, x) static_cast <t> (x)
#define ub upper_bound
#define lb lower_bound
#define pqueue priority_queue
#define mp make_pair
#define pb push_back
#define pof pop_front
#define pob pop_back
#define fi first
#define se second
#define y1 y1_
#define Pi acos(-1.0)
#define iv inline void
#define enter putchar('\n')
#define sum(x) ((int)x.sume())
#define file(x) freopen(x".in", "r", stdin),freopen(x".out", "w", stdout)
typedef double db ;
typedef long long ll ;
typedef unsigned long long ull ;
typedef pair <int, int> pii ;
typedef vector <int> vi ;
typedef vector <pii> vii ;
typedef queue <int> qi ;
typedef queue <pii> qii ;
typedef set <int> si ;
typedef map <int, int> mii ;
typedef map <string, int> msi ;
const int maxn = 2e6 + 100 ;
const int inf = 0x3f3f3f3f ;
const int iinf = 1 << 30 ;
const ll linf = 2e18 ;
const ll mod = 1e9 + 7 ;
const double eps = 1e-7 ;
template <class T = int> T read()
{
	T f = 1, a = 0;
	char ch = getchar() ;
	while (!isdigit(ch)) { if (ch == '-') f = -1 ; ch = getchar() ; }
	while (isdigit(ch)) { a =  (a << 3) + (a << 1) + ch - '0' ; ch = getchar() ; }
	return a * f ;
}

int n;

int a[maxn];

mii s;

bool check(int lim)
{
	s.clear();
	rep(i, 1, n)
	{
		if(a[i] > a[i - 1]) continue;
		while(!s.empty() && (-- s.end()) -> fi > a[i]) s.erase((-- s.end()));
		per(j, a[i], 0)
		{
			if(!j) return 0;
			++ s[j];
			if(s[j] < lim) break;
			s.erase(s.find(j));
		}
	}
	return 1;
}

signed main()
{
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 2, n) if(a[i] <= a[i - 1]) goto binary;
	return puts("1"), 0;
	binary: ;
	int l = 2, r = n, ans;
	while(l <= r)
	{
		int mid = (l + r) >> 1;
		if(check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}