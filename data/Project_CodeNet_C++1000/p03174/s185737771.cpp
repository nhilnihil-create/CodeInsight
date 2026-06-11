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
vector<vector<int>> a;
vector<vector<ll>> dp;
ll fun(int cidx, int mask){
    if(cidx==n) return 1;
    if(dp[cidx][mask]!=-1){
        return dp[cidx][mask];
    }
    ll ans = 0;
    for(int j=0;j<n;++j){
        if(a[cidx][j]==1 && ((mask & (1<<j))== 0)){
            ans = add(ans, fun(cidx+1,mask | (1<<j)));
        }
    }
    return dp[cidx][mask] = ans;
}
int solve(){
    cin>>n;
    a.resize(n, vector<int>(n));
    dp.resize(n+1, vector<ll>(1<<(n+1), -1));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin >> a[i][j];
        }
    }
    cout<<fun(0, 0);

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