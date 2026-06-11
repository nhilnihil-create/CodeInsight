//om nama sivaya
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define INF 9223372036854777ll
#define pb push_back
using namespace std;
ll a[401],pr[401],dp[401][401];
ll pre(ll l,ll r){
    ll x=0,y=0;
    if(l!=0){
        x=pr[l-1];
    }
    y=pr[r];
    return y-x;
    
}
ll ans(ll i,ll j){
    if(i>j)return INF;
    if(i==j)return dp[i][j]=0;
    ll mi=INF;
    if(dp[i][j])return dp[i][j];
    for(ll k=i;k<j;k++){
        mi=min(mi,ans(i,k)+ans(k+1,j)+pre(i,j));
    }
    return dp[i][j]=mi;
}
void solve(){
    ll n;
    cin>>n;
    //int a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
    pr[0]=a[0];
    for(ll i=1;i<n;i++)
    pr[i]=pr[i-1]+a[i];
    cout<<ans(0,n-1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt=1;
    //cin>>tt;
    while(tt--){
        solve();
    }
}
