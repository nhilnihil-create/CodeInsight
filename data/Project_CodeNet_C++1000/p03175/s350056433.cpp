#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> v[100005];
ll dp[100005][2];
const ll m = 1e9 + 7;
ll solve(ll node,ll colour,ll parent){
    ll ans = 0;
    if(dp[node][colour] != -1){
        return dp[node][colour];
    }
    ll way1 = 1;
    for(auto child : v[node]){
        if(child != parent){
            way1 = way1 * solve(child,0,node)%m;
        }
    }
    ans += way1;
    if(!colour){
        ll way2 = 1;
        for(auto child : v[node]){
            if(child != parent){
                way2 = way2 * solve(child,1,node)%m;
            }
        }
    ans += way2;
    }
    return dp[node][colour] = ans%m;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,a,b;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cout<<solve(1,0,-1)<<"\n";
}