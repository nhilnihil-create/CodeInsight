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

ll gcd(ll a, ll b) { while(a) swap(a, b%=a); return b; }

const ll MOD=1000000007LL;

ll ADD(ll x, ll y) { return (x+y) % MOD; }
ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
ll MUL(ll x, ll y) { return x*y % MOD; }
ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }
// ll comb(ll n, ll k) { ll v=1; for(ll i=1; i<=k; i++) v = DIV(MUL(v, n-i+1),i); return v; }
//

bool possible(vi& v, int x){
    int L = v.size();
    set<int> s; s.insert(0);
    rep(i,L) {
        set<int> s2;
        for (int si: s) {
            s2.insert(si + v[i]);
            s2.insert(si - v[i]);
        }
        s = s2;
    }
    // cerr << s << x << endl;
    return found(s, x);
}
bool solve(string&s, int x, int y) {
    int L=s.size();

    vvi ls(2, vi(0));

    int from = 0;
    rep(i,L){
        if (s[i] == 'T') break;
        --x; ++from;
    }
    int dir=0, l=0;
    for (int i=from; i<L; ++i) {
        if (s[i] == 'F') {
            ++l;
        } else {//T
            ls[dir].pb(l);
            dir=1-dir;
            l=0;
        }
    }
    if (l>0) ls[dir].pb(l);

    sort(ALL(ls[0]));
    sort(ALL(ls[1]));
    return possible(ls[0],x) && possible(ls[1],y);
}

int main() {
    string s; cin >> s;
    int x,y; cin >> x >> y;
    cout << (solve(s,x,y) ? "Yes":"No") << endl;
    return 0;
}
