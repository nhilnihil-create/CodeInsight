#include <bits/stdc++.h> 
using namespace std;
vector<int>vi[100005];
const int mod = 1e9 + 7 ;
bool vis[100005];
long long dp[100005][2]; 
void dfs(int node){
    vis[node] = 1;
    long long  ans1 = 1, ans2 = 1;
    for(auto i : vi[node]){
        if(!vis[i]){
            dfs(i);

            ans1 = ((ans1 * dp[i][1]) % mod + (ans1 * dp[i][0]) % mod) % mod;
            ans2 = (ans2 * dp[i][1]) % mod;
        }
    }
    dp[node][1] = ans1, dp[node][0] = ans2;
}
int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n- 1 ; i++){
        int x, y;
        cin>>x>>y;
        vi[x].push_back(y);
        vi[y].push_back(x);
    }
    dfs(1);
    cout<<(dp[1][0] + dp[1][1]) % mod;
	return 0;
}  
