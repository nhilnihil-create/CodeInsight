#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

int n;
vector<int> g[200010];
int dist[200010];


void bfs(int s){
    queue<int> que;
    bool seen[n] = {};
    memset(dist, 0, sizeof(dist));
    que.push(s);
    seen[s] = true;
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(auto nv : g[v]){
            if (seen[nv]) continue;
            seen[nv] = true;
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
}


int main(){
    cin >> n;
    rep(i, n - 1){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs(0);
    int mx = 0;
    rep(i, n) mx = max(mx, dist[i]);

    int ns;
    rep(i, n) {
        if (dist[i] == mx) {
            ns = i;
            break;
        }
    }

    bfs(ns);
    rep(i, n) mx = max(mx, dist[i]);

    cout << (mx%3==1 ? "Second":"First") << endl;

    return 0;
}
