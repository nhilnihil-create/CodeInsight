#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

void minCost(ll ar[] , ll n){
    ll dp[n+1][n+1]={0};
    ll sum[n+1][n+1];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(i==j){
                sum[i][j] = ar[i];
            }
            else{
                sum[i][j] = sum[i][j-1] + ar[j];
            }
        }
    }
    /*
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    */
    for(ll len=2;len<=n;len++){
        for(ll i=0;i<=n-len;i++){
            ll j=i+len-1;
            dp[i][j] = -1;
            for(ll k=i;k<=j-1;k++){
                if(dp[i][j]==-1){
                    dp[i][j] = dp[i][k] + dp[k+1][j] + sum[i][j];
                }
                else
                dp[i][j]=min(dp[i][j], dp[i][k] + dp[k+1][j] + sum[i][j]);
            }
        }
    }
    /*
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    */
    cout<<dp[0][n-1];
}


int main(){
    ll n;
    cin>>n;
    ll ar[n];
    for(ll i=0;i<n;i++){
        cin>>ar[i];
    }
    minCost(ar,n);
}
