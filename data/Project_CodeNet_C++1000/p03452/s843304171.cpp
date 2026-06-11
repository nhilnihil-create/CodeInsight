#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define Task ""

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 5;

vector<pair<int, int>> adj[maxn];
int L[maxn], R[maxn], D[maxn];
int x[maxn];
bool vis[maxn];

void dfs(int u)
{
    vis[u] = 1;
    for (auto v : adj[u]){
        if (vis[v.fi] == 0){
            x[v.fi] = x[u] + v.se;
            dfs(v.fi);
        }
    }
}

signed main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("A.INP", "r")){
        freopen("A.INP", "r", stdin);
        freopen("A.OUT", "w", stdout);
    }
    if (fopen(Task".INP", "r")){
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }
    int N, M; cin >> N >> M;
    for (int i=1; i<=M; ++i){
        cin >> L[i] >> R[i] >> D[i];
        adj[L[i]].pb(mp(R[i], D[i]));
        adj[R[i]].pb(mp(L[i], -D[i]));
    }
    for (int i=1; i<=N; ++i){
        if (vis[i] == 0){
            dfs(i);
        }
    }
    for (int i=1; i<=M; ++i){
        if (x[R[i]] - x[L[i]] != D[i]){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}
