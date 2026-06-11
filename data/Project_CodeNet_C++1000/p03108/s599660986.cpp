#include <iostream>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstring>
#include <string.h>
#include <sstream>
#include <iomanip>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <vector>
#include <random>
#include <chrono>
using namespace std;

#define F first
#define S second
#define siz(v) ((int)v.size())
#define rs(n) resize(n)
#define ALL(v) v.begin(),v.end()
#define reset(v) memset((v),0,sizeof(v))
#define EB emplace_back
#define MP make_pair
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define kiyohime ios::sync_with_stdio(false);cin.tie(0);
#define endl '\n'

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> using vec = vector<T>;
template<typename T> using Prior = priority_queue<T>;
template<typename T> using prior = priority_queue<T, vec<T>, greater<T>>;

const int INF = 1e9;
const ll LLINF = (ll)4*1e18;
const ll MOD = 1e9+7;
const double PI  = 3.14159265358;
const double EPS = 1e-8;
const int xx[8] = {0,1,0,-1,1,1,-1,-1};
const int yy[8] = {1,0,-1,0,1,-1,-1,1};

void pmod(ll &a, ll b) {a = (a+b)%MOD;}
void mmod(ll &a, ll b) {a = (a-b+MOD)%MOD;}
void tmod(ll &a, ll b) {a = (a*b)%MOD;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll POW(ll a, ll b) {ll res=1; do{if(b%2)tmod(res,a);tmod(a,a);}while(b>>=1); return res;}
template<typename T> void amax(T &a, T b) {if(a < b) a = b;}
template<typename T> void amin(T &a, T b) {if(a > b) a = b;}

#define N 100010

int dsu[N];
ll sz[N];

int find(int x){
    return dsu[x] == x ? x : dsu[x] = find(dsu[x]);
}

void unite(int a, int b){
    sz[find(b)] += sz[find(a)];
    dsu[find(a)] = find(b);
}

void solve(){
    int n, m;
    
    cin >> n >> m;
    vec<pii> v(m);
    for(auto &i:v) cin >> i.F >> i.S;
    reverse(ALL(v));
    
    rep1(i, n) dsu[i] = i, sz[i] = 1;
    
    ll k = (ll) n * (n-1) / 2;
    vec<ll> ans;
    ans.EB(k);
    for(auto i:v) {
        if(find(i.F) != find(i.S)){
            k -= sz[find(i.F)] * sz[find(i.S)];
            unite(i.F, i.S);
        }
        ans.EB(k);
    }
    
    reverse(ALL(ans));
    rep1(i, m) cout << ans[i] << ' ' ;
    cout << endl;
}

int main(){
    kiyohime
    int T = 1;
    
//    cin >> T;
    while(T--){
        solve();
    }
}


