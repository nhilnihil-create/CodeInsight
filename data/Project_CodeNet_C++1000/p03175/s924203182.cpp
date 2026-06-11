#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#define ll long long
#define ar array
#define AC ios_base::sync_with_stdio(0);
const int M = 1e9+7;
const int N = 1e5;
using namespace std;
ll dp[N+5][2];
vector<int> adj[N];

void solve(int v, int fa){
    dp[v][1] = dp[v][0] = 1;
    for(int child : adj[v]){
        if(child==fa)
            continue;
        solve(child, v);
        dp[v][1] = (dp[v][1]*(dp[child][0]+dp[child][1]))%M;
        dp[v][0] = (dp[v][0]*dp[child][1])%M;
    }
}

int main(){
    AC
    int n;
    cin>>n;
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    solve(1, 0);
    cout<<(dp[1][0]+dp[1][1])%M<<endl;
}