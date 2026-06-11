#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

bool bfs(vector<vector<int>> &G, vector<int> &seen, int a, int b) {
    queue<int> Q;
    Q.push(0);
    seen[0] = 0;
    int checked = 1;
    while(Q.size()>0) {
        int v = Q.front();
        Q.pop();
        for (auto next:G[v]) {
            if ((v==a && next==b) || (v==b && next==a)) continue;
            else if (seen[next]==-1) {
                Q.push(next);
                seen[next] = 1;
                checked++;
            }
        }
    }
    if (checked==G.size()) return false;
    else return true;
}

int main(){
    int N,M;
    cin >> N >> M;
    vector<P> E;
    vector<vector<int>> G(N);

    rep(i,M) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        E.push_back(make_pair(a,b));
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int ans = 0;

    rep(i,M) {
        vector<int> seen(N,-1);
        int a,b;
        a = E[i].first;
        b = E[i].second;
        if (bfs(G,seen,a,b)) ans++;
    }
    cout << ans << endl;
}
