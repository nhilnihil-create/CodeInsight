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

const int MAX_V = 2e5;
vector<int> es[MAX_V];
int st, en; //端点
vector<int> d(MAX_V, 0);

void dfs(int now, int pre){
    if(pre == -1) d[now] = 0;
    else d[now] = d[pre]+1;
    for(auto &e: es[now]){
        if(e == pre) continue;
        dfs(e, now);
    }
}

int tree_diameter(){
    dfs(0, -1);
    int ret = -1;
    rep(i, MAX_V){
        if(chmax(ret, d[i])) st = i;
    }
    dfs(st, -1);
    ret = -1;
    rep(i, MAX_V){
        if(chmax(ret, d[i])) en = i;
    }
    return ret;
}

int main(){
    int N;
    cin >> N;
    rep(i, N-1){
        int u, v; cin >> u >> v; u--, v--;
        es[u].pb(v), es[v].pb(u);
    }
    int r = tree_diameter();
    if(r%3 == 1) cout << "Second" << endl;
    else cout << "First" << endl;
}