#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

void ways(ll *ar ,int n ,int k){
    ll dp[n+1][k+1]={0};

    for(int j=0;j<=k;j++){
        dp[1][j] = (j<=ar[1]) ? 1 : 0;
    }

    for(int i=2;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(j==0){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = (mod + dp[i][j-1] + dp[i-1][j] - ((j-ar[i]-1 >= 0) ? dp[i-1][j-1-ar[i]]:0))%mod;
            }
        }
    }
    /*
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    cout<<dp[n][k];
}

int main(){
    int n,k;
    cin>>n>>k;
    ll ar[n+1];
    for(int i=1;i<=n;i++){
        cin>>ar[i];
    }
    ways(ar,n,k);
}
