#include <bits/stdc++.h>
using namespace std;

const long long int MOD = 1e9+7;
#define pb push_back
typedef long long ll;
const long long int N = 1e5;



int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<ll>> dp(n+5,vector<ll>(k+5,0));
    vector<vector<ll>> pref(n+5,vector<ll>(k+5,0));

    ll a[n+5];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[i][0]=1;
        pref[i][0]=1;
    }
    for(int i=0;i<=k;i++)  pref[0][i]=1;
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<=k;j++){
            if(a[i]<=j-1)
                dp[i][j]=(pref[i-1][j]-pref[i-1][j-a[i]-1]+MOD)%MOD;
            else
                dp[i][j]=pref[i-1][j];
            if(j>0)
            pref[i][j]=(pref[i][j-1]+dp[i][j])%MOD;
        }
    }
    cout<<dp[n][k];
    return 0;
}