#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;
const int mxN=1e9;
const ll mod = 1e9+7;

ll pow(ll a,ll b){
    ll r =1;
    while(b){
        if(b%2!=0) r=(r*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }

    return r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    vector<ll> v(n);

    for(int i=0;i<n;i++) cin>>v[i];

    vector<ll> pref(n+1);
    pref[0]=0;

    for(int i=1;i<=n;i++){
        pref[i]= pref[i-1]+v[i-1];
    }
    
    ll dp[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j+i<n;j++){
            if(i+j==j)dp[j][j+i]=0;
            else{
                dp[j][i+j]=1e18L+5;
                for(int k =j;k<=j+i-1;k++){
                    dp[j][i+j] = min(dp[j][i+j],dp[j][k]+dp[k+1][i+j]+(pref[i+j+1]-pref[j]));
                }
            }
        }
    }

    cout<<dp[0][n-1];
}