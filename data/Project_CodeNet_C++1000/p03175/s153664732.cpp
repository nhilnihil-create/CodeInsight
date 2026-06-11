#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n;
vector<int> vec[100005];
int visited[100005];
long long int ans[100005][2];
void dfs(int u){
    visited[u] = 1;
    long long int pro1 = 1, pro2 = 1;
        for(int v:vec[u]){
            if(!visited[v]){
                dfs(v);
                long long int a = (ans[v][0] + ans[v][1])%mod;
                long long int b = ans[v][0];
                pro1 = (pro1 *a)%mod;
                pro2 = (pro2 *b)%mod;
            }
        }
        ans[u][0] = pro1;
        ans[u][1] = pro2;
        // cout << u << " " << ans[u][0] << " " << ans[u][1] << "\n";
}
int main(){
    cin >> n;
    for(int i=1;i<n;i++){
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }    
    dfs(1);
    cout << (ans[1][0] + ans[1][1])%mod;
}