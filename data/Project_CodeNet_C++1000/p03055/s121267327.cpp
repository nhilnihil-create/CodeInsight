// Hacheylight
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
//#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define loop(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define cont(i, x) for (int i = head[x]; i; i = e[i].nxt)
#define clr(a) memset(a, 0, sizeof(a))
#define ass(a, sum) memset(a, sum, sizeof(a))
#define lowbit(x) (x & -x)
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
#define enter cout << endl
#define siz(x) ((int)x.size())
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
const int N = 200010 ;
const int INF = 0x3f3f3f3f ;
const int iinf = 1 << 30 ;
const ll linf = 2e18 ;
const int MOD = 1000000007 ;
const double eps = 1e-7 ;
void douout(double x){ printf("%lf\n", x + 0.0000000001) ; }
template <class T> void print(T a) { cout << a << endl ; exit(0) ; }
template <class T> void chmin(T &a, T b) { if (a > b) a = b ; }
template <class T> void chmax(T &a, T b) { if (a < b) a = b ; }
template <class T> void add(T &a, T b) { a = (1ll * a + b) % MOD ; }
template <class T> void mul(T &a, T b) { a = (ll) a * b % MOD ; }
template <class T> T read() {
    int f = 1 ; T x = 0 ;
    char ch = getchar() ;
    while (!isdigit(ch)) { if (ch == '-') f = -1 ; ch = getchar() ; }
    while (isdigit(ch)) { x = x * 10 + ch -'0' ; ch = getchar() ; }
    return x * f ;
}

 // pair <从端点开始的顶点的个数, 端点>


vi g[N] ;
int n ;


pii dfs(int x, int fat) {
	pii ans = mp(0, x) ;
	for (int to : g[x]) {
		if (to == fat) continue ;
		chmax(ans, dfs(to, x)) ;
	}
	ans.fi++ ;
	return ans ;
}

signed main() {
	scanf("%d", &n) ;
	rep(i, 1, n - 1) {
		int a, b ; scanf("%d%d", &a, &b) ;
		g[a].pb(b) ; g[b].pb(a) ;
	}
	int dia = dfs(dfs(1, -1).se, -1).fi ;
	puts((dia % 3 != 2) ? "First" : "Second") ;
	return 0 ;
}

/*
写代码时请注意：
	1.ll？数组大小，边界？数据范围？
	2.精度？
	3.特判？
	4.至少做一些
思考提醒：
	1.最大值最小->二分？
	2.可以贪心么？不行dp可以么
	3.可以优化么
	4.维护区间用什么数据结构？
	5.统计方案是用dp？模了么？
	6.逆向思维？
*/



