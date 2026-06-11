#include <bits/stdc++.h>
using namespace std;

#define NDEBUG
#ifdef DEBUG
#include "../cout11.h"
#undef NDEBUG
#endif
#include <cassert>

typedef long long ll;
typedef long double Double;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef pair<double,double> dd;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long double> vD;

#define sz(a)  int((a).size())
#define pb  push_back
#define FOR(var,from,to) for(int var=(from);var<=(to);++var)
#define rep(var,n)  for(int var=0;var<(n);++var)
#define rep1(var,n)  for(int var=1;var<=(n);++var)
#define repC2(vari,varj,n)  for(int vari=0;vari<(n)-1;++vari)for(int varj=vari+1;varj<(n);++varj)
#define ALL(c)  (c).begin(),(c).end()
#define RALL(c)  (c).rbegin(),(c).rend()
#define tr(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define mid(x,y) ((x)+((y)-(x))/2)
#define IN(x,a,b) ((a)<=(x)&&(x)<=(b))
#define cons make_pair


ll gcd(ll a, ll b) { while(a) swap(a, b%=a); return b; }

const ll MOD=1000000007LL;

ll ADD(ll x, ll y) { return (x+y) % MOD; }
ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
ll MUL(ll x, ll y) { return x*y % MOD; }
ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }
// ll comb(ll n, ll k) { ll v=1; for(ll i=1; i<=k; i++) v = DIV(MUL(v, n-i+1),i); return v; }
//
ll FACT(ll n) {
    ll fact_n = 1LL;
    rep1(i,n) fact_n = MUL(fact_n, i);
    return fact_n;
}

#define INTSPACE 12
char _buf[INTSPACE*1000000 + 3];

int loadint() {
    if (fgets(_buf, INTSPACE+3, stdin)==NULL) return 0;
    return atoi(_buf);
}

int loadvec(vector<int>& v, int N=-1) {
    if (N == -1) {
        N = loadint();
        if (N==0) return 0;
    }
    int bufsize = INTSPACE*N + 3;
    if (fgets(_buf, bufsize, stdin)==NULL) return 0;
    v.resize(N);

    int i=0;
    bool last = false;
    for (char *p=&_buf[0]; ;) {
        char *q = p;
        while (*q > ' ') ++q;
        if (*q == 0x0D || *q == 0x0A) last = true;
        *q = 0;
        v[i++] = atoi(p);
        if (last || i == N) break;
        p = q+1;
    }
    // assert(i <= N);
    return i;
}
void read_cr() {
    fgets(_buf, 256, stdin);
}

ll solve(int N, vi& a) {
    vector<ll> inv(N+1);
    for (int n=1; n<=N; ++n) inv[n] = DIV(1, n);
    vector<ll> inv_acc(N+1, 0);
    for (int n=1; n<=N; ++n) inv_acc[n] = inv_acc[n-1] + inv[n];
#ifdef DEBUG
    cerr << inv << endl;
    cerr << inv_acc << endl;
#endif
    ll fact_n = FACT(N);

    ll ans = 0;
    rep(i,N){
        ll p = ADD(SUB(inv_acc[N-i], inv_acc[0]),
                   SUB(inv_acc[1+i], inv_acc[1]));
        // fprintf(stderr, "i=%d: p=%lld\n", i, p);
        ans = ADD(ans, MUL(p, a[i]));
    }
    ans = MUL(ans, fact_n);
    return ans;
}

double solve_f(int N, vi& a) {
  vector<double> inv(N + 1);
  for (int n = 1; n <= N; ++n) inv[n] = 1.0 / n;
  vector<double> inv_acc(N + 1, 0);
  for (int n = 1; n <= N; ++n) inv_acc[n] = inv_acc[n - 1] + inv[n];
#ifdef DEBUG
  cerr << inv << endl;
  cerr << inv_acc << endl;
#endif
//   ll fact_n = FACT(N);
  double fact_n = 1.0; rep1(i,N) fact_n *= i;

  double ans = 0;
  rep(i, N) {
    double p = (inv_acc[N - i] - inv_acc[0])
             + (inv_acc[1 + i] - inv_acc[1]);
    // fprintf(stderr, "i=%d: p=%g\n", i, p);
    ans += p * a[i];
  }
  ans *= fact_n;
  return ans;
}

int main() {
    vi a;
    int N = loadvec(a);
    cout << solve(N,a) << endl;
    // cout << solve_f(N,a) << endl;
    return 0;
}
