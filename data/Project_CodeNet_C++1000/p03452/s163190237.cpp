#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007LL;
const int INF = LLONG_MAX;

bool dfs(int cur, vector<vector<pair<int, int> > > &G, vector<int> &x, int cost){
    x[cur] = cost;
    bool ret = true;
    for(auto nxt : G[cur]){
        
        if(x[nxt.second] == -INF){
            //cout << cur << " " << nxt.second << " " << cost + nxt.first << endl;
            ret = dfs(nxt.second, G, x, cost + nxt.first);
            if(ret == false) return false;
        }else{
            if(x[nxt.second] - cost != nxt.first) return false;
        }
    }

    return true;
}

signed main(){
    
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int> > > G(n);
    for(int i = 0; i < m; i++){
        int l, r, d; cin >> l >> r >> d;
        l--;
        r--;
        G[l].push_back({d, r});
        G[r].push_back({-d, l});
    }

    bool ans = true;
    vector<int> x(n, -INF);
    for(int i = 0; i < n; i++){
        if(x[i] == -INF){
            if(!dfs(i, G, x, 0LL)) ans = false;
        }
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}