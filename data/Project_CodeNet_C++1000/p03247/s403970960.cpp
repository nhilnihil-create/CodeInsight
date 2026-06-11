#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
//#define db double
#define all(x) x.begin(), x.end()
#define SZ(x) (int)(x.size())
#define mem(x, y) memset(x, y, sizeof(x))
#define what_is(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << (x) << endl;
#define suf_zero(x) __builtin_ffs(x)
#define pre_zero(x) __builtin_clz(x)
#define num_one(x) __builtin_popcount(x)
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define mt make_tuple
#define mp make_pair
#define eb push_back
#define pb push_back
#define INFI 2000000009
#define INFLL (ll)1e18+7
#define ig ignore
#define fi first
#define TP tuple<int, int, int>
#define se second
//#define lson l, mid, rt<<1
//#define rson mid+1, r, rt<<1|1
#define PII pair<int, int>
//void print(__int128 x){if(x>9)print(x/10);putchar('0'+x%10);}
#define rep(i, begin, end) for(__typeof(end) i =(begin)-((begin)>(end));i!=(end)-((begin)>(end));i+=1-2*((begin)>(end)))
void err(istream_iterator<string> it) {cerr<<endl;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << " , ";
    err(++it, args...);
}// fast IO
auto TIMESTART = chrono::steady_clock::now();
auto TIMESTOP  = chrono::steady_clock::now();
void TimeStop()
{
    TIMESTOP = chrono::steady_clock::now();
    auto ElapsedTime = TIMESTOP - TIMESTART;
    cout << "\n\nTime elapsed: " << chrono::duration<double>(ElapsedTime).count() << " seconds.\n";
}
namespace fastIO{
    #define BUF_SIZE 2000000
//     fread -> read
    bool IOerror = 0;
    static char obuf[BUF_SIZE], *OUT=obuf;
    inline char nc(){
        static char buf[BUF_SIZE], *p1 = buf+BUF_SIZE,
         *pend = buf+BUF_SIZE;
         if(p1==pend){
             p1 = buf;
             pend = buf+fread(buf, 1, BUF_SIZE, stdin);
             if(pend==p1){
                 IOerror = 1;
                 return -1;
             }
         }
         return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline void read(int &x){
        char ch;
        while(blank(ch=nc()));
        if(IOerror)return ;
        for(x=ch-'0';(ch=nc())>='0'&&ch<='9';x=x*10+ch-'0');
    }
    inline void read(ll &x){
        char ch;
        while(blank(ch=nc()));
        if(IOerror)return ;
        for(x=ch-'0';(ch=nc())>='0'&&ch<='9';x=x*10+ch-'0');
    }
    void print(const int& x) {
        if(x > 9) print(x / 10);
        *OUT++= x % 10 + '0';
    }
    void print(const ll& x) {
        if(x > 9) print(x / 10);
        *OUT++= x % 10 + '0';
    }
    void print(){fwrite(obuf, OUT-obuf, 1, stdout);}
    #undef BUF_SIZE
}
using namespace fastIO;
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/hash_policy.hpp>
//using namespace __gnu_pbds;
//mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
const double pi = acos(-1.0);
const double eps = 1e-8;
const int mod = 1e9+7;
#define mul(a, b) 1LL * (a) * (b) % mod
#define add(a, b) (a + b >= mod ? a + b - mod : a + b)
#define sub(a, b) (a - b <  0 ? a - b + mod : a - b)
#define RG register
///////////// BOUND /////////////////
ll qp(ll b, ll n, const ll mod=::mod){ll r=1;if(n<0)n+=mod-1;b%=mod;for(;n;n>>=1,b=mul(b,b))if(n&1)r=mul(r,b);return r;}
#define inv(x) (qp((x), mod-2))
//const ll inv2 = (mod+1)/2;
//const ll inv6 = qp(6, mod-2);
//ll sum_of_sq(ll n){n%=mod;return n*(n+1)%mod*(2*n+1)%mod*inv6%mod;}
//tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> T;
//cc_hash_table<ll, ll> Sf, Sg, Sh;
/////////////// Macro ///////////////
const int maxn = 1e5+7;
pair<ll, ll> a[maxn];
int main()
{
    #ifdef aoaoao
//    freopen("in.txt", "r", stdin);
//    freopen("me.txt", "w", stdout);
    #endif // aoaoao
    int n;scanf("%d", &n);
    map<int, int> vis;
    int mx = 0;
    for(int i=1;i<=n;++i)
    {
        scanf("%lld%lld", &a[i].fi, &a[i].se);
        vis[((a[i].fi+a[i].se)%2+2)%2]++;
    }
    if(SZ(vis)==2) return puts("-1"), 0;
    int ok = 0;
    if(vis.begin()->fi==0) ok = 1;
    mx = 31;
    printf("%d\n", mx+ok);
    if(ok)
    {
        cout << 1 << ' ';
        for(int i=1;i<=n;++i) a[i].fi--;
    }
    for(int i=0;i<mx;++i) printf("%lld%c", 1LL<<i, " \n"[i+1==mx]);
    for(int i=1;i<=n;++i)
    {
        if(ok) cout << 'R';
        char str[50];str[mx]='\0';
        for(int j=mx-1;j>=0;--j)
        {
            if(abs(a[i].fi)>=abs(a[i].se))
            {
                if(a[i].fi>0)str[j]='R', a[i].fi-=1LL<<j;
                else str[j]='L', a[i].fi+=1LL<<j;
            }
            else
            {
                if(a[i].se>0)str[j]='U', a[i].se-=1LL<<j;
                else str[j]='D', a[i].se+=1LL<<j;
            }
        }
        cout << str << endl;
    }
}
