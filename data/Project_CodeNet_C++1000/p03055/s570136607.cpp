#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> Path(200001);
ll Max = 0;
ll idx = 0;
bool grid[200001];

ll N;
vector<vector<ll>> G;

int dfs(ll x, ll cnt){
    bool flag = true;
    for(auto v : G[x]){
        if(!grid[v]){
            grid[v] = true;
            flag = false;
            dfs(v, cnt+1);
        }
    }
    if(flag) {
        if(Max < cnt){
            Max = cnt;
            idx = x;

        }
    }
    return 0;

}

int main(){
    cin >> N;
    G.resize(N); 
    for(int i = 0;i < N-1; i++){
        ll a, b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 最長パス
    vector<bool> DP(N);
    DP[1] = DP[4] = false;
    DP[2] = DP[3] = true;
    for(int i = 5; i < N; i++){
         if(i % 3 == 1) DP[i] = false;
         else DP[i] = true;
    }
    if(N <= 4){
        if(N == 2) cout << "second" << endl;
        else cout << "First" << endl;
        return 0;
    }

    
    memset(grid, false, sizeof(grid)); grid[0] = true;
    dfs(0, 0);
    memset(grid, false, sizeof(grid)); grid[idx] = true;
    dfs(idx, 0);
    if(DP[Max]) cout << "First" << endl;
    else cout << "Second" << endl;


}