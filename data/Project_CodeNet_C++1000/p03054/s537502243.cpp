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
#define int long long
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

int H, W, n, x, y, preS[4][N], preT[4][N], f[4] ;
char s[N], t[N] ;

signed main() {
	scanf("%lld%lld%lld%lld%lld", &H, &W, &n, &x, &y) ;
    scanf("%s%s", s + 1, t + 1) ;
    f[0] = H - x + 1 ;
    f[1] = x ;
    f[2] = y ;
    f[3] = W - y + 1 ;
    rep(i, 1, n) {
    	rep(j, 0, 3) preS[j][i] = preS[j][i - 1], preT[j][i] = preT[j][i - 1] ;
    	if (s[i] == 'D') ++preS[0][i] ;
    	if (s[i] == 'U') ++preS[1][i] ;
    	if (s[i] == 'L') ++preS[2][i] ;
    	if (s[i] == 'R') ++preS[3][i] ;
		if (t[i] == 'D') ++preT[0][i] ;
    	if (t[i] == 'U') ++preT[1][i] ;
    	if (t[i] == 'L') ++preT[2][i] ;
    	if (t[i] == 'R') ++preT[3][i] ;
    	rep(j, 0, 3) if (preT[j][i] - preS[j ^ 1][i] >= f[j]) preT[j][i]-- ;
	}
	rep(i, 1, n)
	rep(j, 0, 3)
	if (preS[j][i] - preT[j ^ 1][i - 1] >= f[j]) print("NO") ;
   	printf("YES\n") ;
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



