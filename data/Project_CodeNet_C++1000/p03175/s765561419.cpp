#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
                     
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
const ll mod = 1e9+7;
ll mult(ll a,ll b){return ((a%mod)*(b%mod))%mod;}
ll add(ll a,ll b){return ((a%mod)+(b%mod))%mod;}
ll sub(ll a,ll b){return ((a%mod)-(b%mod)+mod)%mod;} 
int n;
vector<vector<ll>> dp;
vector<int> v[100009];
void dfs(int cur, int par){
    dp[cur][0] = 1, dp[cur][1] = 1;
    for(auto &neigh: v[cur]){
        if(neigh == par) continue;
        dfs(neigh, cur);
        dp[cur][1] = mult(dp[cur][1], dp[neigh][0]);
        dp[cur][0] = mult(dp[cur][0], add(dp[neigh][0], dp[neigh][1]));
    }
}

int solve(){
    cin>>n;
    dp.resize(n+1, vector<ll>(2, 0));
    for(int i=0;i<n-1;++i){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0);
    cout<<add(dp[1][0] , dp[1][1]);
    return 0;
}
int main(){
    fast;
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}