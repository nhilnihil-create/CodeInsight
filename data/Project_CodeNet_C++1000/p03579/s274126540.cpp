#include <bits/stdc++.h>
#define rep(i, n)  for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

bool dfs(vector<vector<int>> &G, vector<int> &C, int v, int c = 0){
    C[v] = c;
    
    for(auto next_v : G[v]){
        if(C[next_v] != -1){
            if(C[next_v] == c) return false;
            continue;
        }
        if(!dfs(G, C, next_v, 1 - c)) return false;
    }
    return true;
}


int main(){
    ll N, M; cin >> N >> M;
    vector<vector<int>> G(N);
    rep(i, M){
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> C;
    C.assign(N, -1);
    bool isBiGraph = dfs(G, C, 0);
    ll ans;
    if(isBiGraph){
        ll cnt_0 = 0;
        ll cnt_1 = 0;
        rep(i, N){
            if(C[i] == 0) ++cnt_0;
            if(C[i] == 1) ++cnt_1;
        }
        ans = cnt_1 * cnt_0 - M;
    }else{
        ans = N * (N-1) / 2 - M;
    }
    cout << ans << endl;
}