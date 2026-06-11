#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

const int MAX_V = 1e5;
set<int> es[MAX_V], rs[MAX_V];
int par[MAX_V];

int main(){
    int N, M;
    cin >> N >> M;
    rep(i, N+M-1){
        int u, v; cin >> u >> v; u--, v--;
        es[u].insert(v), rs[v].insert(u);
    }
    int root;
    rep(i, N){
        if(sz(rs[i]) == 0) root = i;
    }
    par[root] = -1;
    queue<int> que;
    que.push(root);
    while(!que.empty()){
        int i = que.front();
        que.pop();
        for(auto &e: es[i]){
            if(sz(rs[e]) == 1){
                que.push(e);
                par[e] = i;
            }
            else rs[e].erase(i);
        }
    }
    rep(i, N) cout << par[i]+1 << endl;
}