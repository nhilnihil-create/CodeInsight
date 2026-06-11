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
#define loop(s, v, it) for (s::iterator it = v.begin(); it != v.end(); it++)
#define cont(i, x) for (int i = head[x]; i; i = e[i].nxt)
#define clr(a) memset(a, 0, sizeof(a))
#define ass(a, sum) memset(a, sum, sizeof(a))
#define lowbit(x) (x & -x)
#define all(x) x.begin(), x.end()
#define ub upper_bound
#define lb lower_bound
#define pq priority_queue
#define mp make_pair
#define pb push_back
#define pof pop_front
#define pob pop_back
#define fi first
#define se second
#define iv inline void
#define enter cout << endl
#define siz(x) ((int)x.size())
#define file(x) freopen(#x".in", "r", stdin),freopen(#x".out", "w", stdout)
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
template <class T> void upd(T &a, T b) { (a += b) %= MOD ; }
template <class T> void mul(T &a, T b) { a = (ll) a * b % MOD ; }


int n,Q;
char s[N],t[N],d[N];
int Drop(int x)
{
    for(int i=1;i<=Q;i++)
    {
        if(s[x]==t[i]) x+=(d[i]=='R')?1:-1;
        if(x>n) return -1;
        if(x<1) return 1;
    }
    return 0;
}
int main()
{
    cin>>n>>Q;
    scanf("%s",s+1);
    for(int i=1;i<=Q;i++) cin>>t[i]>>d[i];
    int l=1,r=n,la=0,ra=n+1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(Drop(mid)==1) la=mid,l=mid+1;
        else r=mid-1;
    }
    l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(Drop(mid)==-1) ra=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<ra-la-1<<endl;
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


