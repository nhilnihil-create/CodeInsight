#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lld long double
#define w(x) ll x;cin>>x;while(x--)
#define mod 1000000007
#define speed ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main(){
    speed;
    ll n,k; cin>>n>>k;
    vector<ll> a(n);    for(auto &i:a)  cin>>i;
    vector<ll> dp(n,0);
    dp[n-1]=0;
    for(ll i=n-2;i>=0;i--){
        ll mn=INT_MAX;
        for(ll j=1;j<=k&&(i+j)<=n-1;j++){
            mn=min(mn,(abs(a[i+j]-a[i])+dp[i+j]));
        }
        dp[i]=mn;
    }
    cout<<dp[0]<<'\n';
    return 0;
}