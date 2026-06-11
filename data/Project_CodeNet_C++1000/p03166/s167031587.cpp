#include<iostream>
#include<vector>
#define MAX_N 200050

using namespace std;

vector<int> G[MAX_N];
int n,m;
int dp[MAX_N];

int dfs(int u){
    if(dp[u] != -1) return dp[u];
    int res = 0;
    for(auto v : G[u]){
        res = max(res,dfs(v)+1);
    }
    return dp[u] = res;
}

int main(){
    cin >> n >> m;
    for(int i=0;i < m;i++){
        int x,y;
        cin >> x >> y;
        --x;--y;
        G[x].push_back(y);
    }
    for(int i=0;i < MAX_N;i++) dp[i] = -1;
    int ans = 0;
    for(int i=0;i < n;i++){
        ans = max(ans,dfs(i));
    }

    cout << ans << endl;
    return 0;
}