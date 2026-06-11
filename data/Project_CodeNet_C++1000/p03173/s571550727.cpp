#include <bits/stdc++.h>
using namespace std;

const long long int MOD = 1e9+7;
#define pb push_back
typedef long long ll;
const long long int N = 1e5;



int main(){
    int n;
    cin>>n;
    vector<vector<ll>> dp(n+5,vector<ll>(n+5,0));
    vector<ll> pref(n+5 , 0);
    ll a[n+5];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pref[i]=pref[i-1]+a[i];
        dp[i][i]=0;
    }
    for(ll i=n;i>=1;i--){
        for(ll j=i+1;j<=n;j++){
            dp[i][j]=pref[j]-pref[i-1];
            ll temp=1e18;
            for(int k=i;k<j;k++){
                temp=min(temp,dp[i][k]+dp[k+1][j]);
            }
            if(j>i+1)
            dp[i][j]+=temp;
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<dp[1][n];
    return 0;
}