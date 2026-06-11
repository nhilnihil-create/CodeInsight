#include <bits/stdc++.h>
using namespace std;

#define NDEBUG
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

#define INTSPACE 12
char _buf[INTSPACE*1000000 + 3];

int loadint() {
    if (fgets(_buf, INTSPACE+3, stdin)==NULL) return 0;
    return atoi(_buf);
}

int loadvec(vector<int>& v, int N=-1) {
    if (N == 0) {
        v.clear();
        return 0;
    }
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
    return i;
}
void read_cr() {
    fgets(_buf, 256, stdin);
}



int N, X;
vi x;

typedef __int128_t LL;

vector<LL> acc;


inline ostream& operator<<(ostream &s, __int128_t x) {
    __int128_t tmp = x < 0 ? -x : x;

    int base = 10;
    auto f = s.flags();
    if (f & s.oct) base = 8;
    else if (f & s.hex) base = 16;

    stack<char> st;
    while (tmp) {
        st.push("0123456789ABCDEF"[tmp % base]);
        tmp /= base;
    }
    if (x < 0) {
        st.push('-');
    }
    while (!st.empty()) {
        s << st.top();
        st.pop();
    }
    return s;
}

LL foo(int w) {
    LL ans = (LL)X * w;
    ans += (LL)5 * (acc[w] - acc[0]) + (LL)X*w;

    for (int i=w,k=5; i<N; i+=w,k+=2) {
        int from = i, to = min(i+w, N);
        ans += (LL)k * (acc[to] - acc[from]) + (LL)X*(to - from);
    }
    return ans;
}

LL solve() {
    LL ans = LLONG_MAX;
    for (int w=1; w<=N; ++w) {
        LL a = foo(w);
        ans = min(ans, a);
    }
    return ans;
}

int main() {
    scanf("%d%d", &N, &X);
    read_cr();
    x.resize(N);
    loadvec(x, N);;

    reverse(ALL(x));

    acc.resize(N+1);
    acc[0] = 0;
    rep(i,N) acc[i+1] = acc[i] + (LL)x[i];

    cout << solve() << endl;
    return 0;
}
