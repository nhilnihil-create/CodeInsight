#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e8;
const ll INF = 1e16;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

const int MAX_N = 1e4;
int N, n;
vector<int> es[MAX_N];
int c[MAX_N];
bool used[MAX_N];

void dfs(int now){
    c[now] = n;
    used[now] = true;
    n--;
    for(auto &e: es[now]){
        if(!used[e]) dfs(e);
    }
}

int main(){
    cin >> N;
    rep(i, N-1){
        int u, v;
        cin >> u >> v;
        u--, v--;
        es[u].pb(v), es[v].pb(u);
    }
    int sum = 0, a[N];
    rep(i, N){
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a+N);
    cout << sum-a[N-1] << endl;
    n = N-1;
    dfs(0);
    rep(i, N) cout << a[c[i]] << ' ';
    cout << endl;
}