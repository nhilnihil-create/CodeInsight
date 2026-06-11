#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll a[22][22];
ll n;
const ll m = 1e9 + 7;
ll dp[22][1<<21];
ll solve(ll index,ll mask){
    if(index == n){
        return 1;
    }
    if(dp[index][mask] != -1){
        return dp[index][mask];
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        if(((mask >> i) & 1) && a[index][i]){
            ans = (ans + solve(index+1,mask^(1<<i)))%m;
        }
    }
    return dp[index][mask] = ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    cout<<solve(0,(1<<n) - 1)<<"\n";
}