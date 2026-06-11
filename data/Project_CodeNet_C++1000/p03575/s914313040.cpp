#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

vector<bool> seen;
vector<int> a, b;
void dfs(const vector<vector<int> > &graph, int v, int i){
    seen[v] = true;

    for(auto next_v : graph[v]){
        if((v==a[i] && next_v==b[i]) || (v==b[i] && next_v==a[i])) continue;
        if(seen[next_v]) continue;
        dfs(graph, next_v, i);
    }
}

int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int> > edges(n);
    rep(i, m){
        int ai, bi;
        cin >> ai >> bi;
        --ai, --bi;
        a.push_back(ai);
        b.push_back(bi);
        edges[ai].push_back(bi);
        edges[bi].push_back(ai);
    }

    int ans = 0;
    rep(i, m){
        int cnt = 0;
        seen.assign(n, false);
        rep(k, n){
            if(seen[k]) continue;

            dfs(edges, k, i);
            cnt++;
        }
        if(cnt > 1) ans++;
    }
    
    cout << ans << endl;
    return 0;
}