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
    ll n;   cin>>n;
    vector<ll> a(n);    for(auto &i:a)  cin>>i;
    vector<ll> dp(n,0);
    dp[n-1]=0;
    for(ll i=n-2;i>=0;i--){
        if(i+2>n-1){
            dp[i]=abs(a[i+1]-a[i])+dp[i+1];
        }
        else{
            dp[i]=min((abs(a[i+1]-a[i])+dp[i+1]),(abs(a[i+2]-a[i])+dp[i+2]));
        }
    }
    cout<<dp[0]<<'\n';
    return 0;
}