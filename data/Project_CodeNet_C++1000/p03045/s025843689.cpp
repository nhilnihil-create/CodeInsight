#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

vector<vector<int>>G;
vector<int> visited;

void dfs(int i) {
    for(int next : G[i]) {
        if(visited[next]) continue;
        visited[next] = true;
        dfs(next);
    }
}

int main() {
    int N, M; cin >> N >> M;
    int X[M], Y[M], Z[M];
    G.resize(N);
    visited.resize(N, false);
    rep(i, M) {
        cin >> X[i] >> Y[i] >> Z[i];
        --X[i], --Y[i];
        G[X[i]].pb(Y[i]);
        G[Y[i]].pb(X[i]);
    }
    int ans = 0;
    rep(i, N) {
        if(visited[i])continue;
        ++ans;
        visited[i] = true;
        dfs(i);
    }
    cout << ans << endl;
}
