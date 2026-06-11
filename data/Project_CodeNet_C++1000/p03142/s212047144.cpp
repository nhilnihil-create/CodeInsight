#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define int long long
#define double long double
#define all(a) a.begin(), a.end()
#define debug(x) cout << #x << " = " << x << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

const int mx = 100005;

int N, M;
int par[mx];
bool used[mx];
vector<int> sorted;
vector<int> G[mx];

void dfs(int v){
    if(used[v])return;
    used[v] = true;
    for(int i : G[v])dfs(i);
    sorted.push_back(v);
}

void dfs2(int v, int p){
    if(used[v])return;
    used[v] = true;
    par[v] = p + 1;
    for(int i : G[v])dfs2(i, v);
}

signed main(void){

    int N, M; cin >> N >> M;
    rep(i, N + M - 1){
        int a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
    }

    rep(i, N)dfs(i);
    reverse(all(sorted));
    vector<int> order(N);
    rep(i, N)order[sorted[i]] = i;

    rep(i, N){
        sort(all(G[i]), [&](int x, int y){
            return order[x] < order[y];
        });
    }

    memset(used, false, sizeof(used));
    dfs2(sorted[0], -1);

    rep(i, N)cout << par[i] << endl;
    return 0;

}