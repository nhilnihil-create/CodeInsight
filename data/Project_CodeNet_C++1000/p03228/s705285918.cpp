#pragma GCC target ("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<random>
#include<functional>
#include<algorithm>
#include<stack>
#include<cstdio>
#include<cstring>
#include<bitset>
#include<unordered_map>
#include<climits>
#include<fstream>
#include<complex>
#include<time.h>
#include<cassert>
#include<functional>
#include<numeric>
#include<tuple>
using namespace std;
using ll = long long;
using ld = long double;
#define int long long
#define all(a) (a).begin(),(a).end()
#define fs first
#define sc second
#define xx first
#define yy second.first
#define zz second.second
#define H pair<int, int>
#define P pair<int, pair<int, int>>
#define Q(i,j,k) mkp(i,mkp(j,k))
#define rng(i,s,n) for(int i = (s) ; i < (n) ; i++)
#define rep(i,n) rng(i, 0, (n))
#define mkp make_pair
#define vec vector
#define pb emplace_back
#define crdcomp(b) sort(all((b)));(b).erase(unique(all((b))),(b).end())
#define getidx(b,i) lower_bound(all(b),(i))-b.begin()
#define ssp(i,n) (i==(int)(n)-1?"\n":" ")
#define ctoi(c) (int)(c-'0')
#define itoc(c) (char)(c+'0')
#define cyes printf("Yes\n")
#define cno printf("No\n")
#define cdf(n) int quetimes_=(n);rep(qq123_,quetimes_)
#define gcj printf("Case #%lld: ",qq123_+1)
#define readv(a,n) a.resize(n,0);rep(i,(n)) a[i]=read()
//#define endl "\n"
constexpr int mod = 1e9 + 7;
constexpr int Mod = 998244353;
constexpr int MXN = 500000 + 100;
constexpr ld EPS = 1e-10;
constexpr ll inf = 3 * 1e18;
constexpr int Inf = 15 * 1e8;
const vec<int>dx{ -1,1,0,0 }, dy{ 0,0,-1,1 };
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
ll read() { ll u, k = scanf("%lld", &u); return u; }
string reads() { string s; cin >> s; return s; }
H readh(bool g = 0) { H u; int k = scanf("%lld %lld", &u.fs, &u.sc); if (g) u.fs--, u.sc--; return u; }
bool ina(H t, int h, int w) { return 0 <= t.fs && t.fs < h && 0 <= t.sc && t.sc < w; }
bool ina(int t, int l, int r) { return l <= t && t < r; }
ll gcd(ll i, ll j) { return j ? gcd(j, i % j) : i; }
ll mod_pow(ll x, ll n, ll p = mod) {
    ll res = 1; x %= p;
    while (n > 0) {
        if (n & 1) res = res * x % p;
        x = x * x % p;
        n >>= 1;
    }
    return res;
}//x^n%p
ll bitcount(ll x) {
    int sum = 0; for (int i = 0; i < 60; i++)if ((1ll << i) & x) sum++;
    return sum;
}
/*constexpr int fn_ = 5000005;
ll fact_[fn_], comp_[fn_];
ll comb(ll x, ll y, ll m) {
    if (!fact_[0]) {
        fact_[0] = 1; comp_[0] = 1;
        for (int i = 1; i < fn_; i++)
            fact_[i] = fact_[i - 1] * i % m;
        comp_[fn_ - 1] = mod_pow(fact_[fn_ - 1], m - 2, m);
        for (int i = fn_ - 2; i > 0; i--)
            comp_iiiiiiiiiiiijijiii[i] = comp_[i + 1] * (i + 1) % m;
    }
    if (x < y) return 0;
    return fact_[x] * comp_[x - y] % m * comp_[y] % m;
}*/
//--------------------------------------------------------------
signed main() {
    int a, b, k; cin >> a >> b >> k;
    rep(i, k) {
        if (i % 2 == 0) {
            if (a % 2 == 1) a--;
            b += a / 2, a /= 2;
        }
        else {
            if (b % 2 == 1)b--;
            a += b / 2, b /= 2;
        }
    }
    cout << a << " " << b << endl;
}