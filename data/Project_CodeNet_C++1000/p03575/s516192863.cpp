/**
*	created: 10.09.2020 00:25:37
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

struct graph {
    vector<vector<int>> to;
    vector<P> bri;
    vector<int> art, ord, low;
    vector<bool> vis;
    graph(int n) : ord(n,0), low(n,0), vis(n,false), to(n) {}

    void lowlink(int v, int p, int &t) { 
        vis[v] = true;
        ord[v] = t++;
        low[v] = ord[v]; // initialize
        bool isart = false; int cnt = 0;
        for (auto i : to[v]) {
            if(!vis[i]) {
                cnt++; lowlink(i,v,t); chmin(low[v],low[i]);
                if (!p && ord[v] <= low[i]) isart = true;
                if (ord[v] < low[i]) bri.push_back(P(min(v,i),max(v,i)));
            }
            else if (i != p) chmin(low[v],ord[i]);
        }
        if (p == -1 && cnt > 1) isart = true;
        if(isart) art.push_back(v);
    }
};

signed main() {
    int n, m; cin >> n >> m;
    graph G(n);
    rep(i,m) {
        int a, b; cin >> a >> b;
        a--; b--;
        G.to[a].push_back(b);
        G.to[b].push_back(a);
    }
    int t = 0;
    rep(i,n) G.lowlink(i,-1,t);
    cout << G.bri.size() << endl;
    return 0;
}
