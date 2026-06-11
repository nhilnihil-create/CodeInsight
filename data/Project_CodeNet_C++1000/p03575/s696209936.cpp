/**
*	created: 09.09.2020 23:44:10
**/
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;
using namespace std;
using ll = long long;
using P = pair<int,int>;
// #define endl '\n'
#define int long long
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define rrep(i,n) for (int i = (int)(n - 1); i >= 0; i--)
#define rep2(i,s,n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pcnt(bit) __builtin_popcountll(bit)
const long double pi = acos(-1.0);
const int MAX = 1000010;
const int INF = 1ll << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
template<typename T> inline bool chmax(T &a, T &b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T> inline bool chmin(T &a, T &b) {if (b < a) {a = b; return 1;} return 0;}
template<typename T> T pow(T a, ll n) {T r(1); while(n) {if (n & 1) r *= a; a *= a; n >>= 1;} return r;}
struct faster_io {faster_io() {cin.tie(0); ios_base::sync_with_stdio(false);}} faster_io_;

vector<int> g[MAX];
vector<P> bri;
vector<int> art;
int ord[MAX], low[MAX];
bool vis[MAX];

void lowlink(int v, int p, int &k) {
    vis[v] = true;
    ord[v] = k++;
    low[v] = ord[v]; // initialize lowlink
    bool isart = false;
    int cnt = 0;
    for (auto i : g[v]) {
        if(!vis[i]) {
            cnt++;
            lowlink(i,v,k);
            chmin(low[v],low[i]);
            if (!p && ord[v] <= low[i]) isart = true;
            if (ord[v] < low[i]) bri.push_back(P(min(v,i),max(v,i)));
        }
        else if (i != p) chmin(low[v],ord[i]);
    }
    if (p == -1 && cnt > 1) isart = true;
    if(isart) art.push_back(v);
}

signed main() {
    int n, m; cin >> n >> m;
    rep(i,m) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int k = 0;
    rep(i,n) if(!vis[i]) lowlink(i,-1,k);
    cout << bri.size() << endl;
    return 0;
}