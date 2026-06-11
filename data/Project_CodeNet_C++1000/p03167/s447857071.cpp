#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = (ll)1e9+7;
#define wall '#'

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);  cout.tie(0);
}

int main() {
    fast();
    ll H,W;
    cin >>H >>W;
    char matrix[H][W];
    for(ll i=0;i<H;i++){
        cin >>matrix[i];
    }
    
    ll dp[H][W];
    
    dp[0][0]=1;
    for(ll i=1;i<H;i++){
        if(matrix[i][0]==wall){
            dp[i][0]=0;
        }
        else dp[i][0] = dp[i-1][0];
    }
    for(ll j=1;j<W;j++){
        if(matrix[0][j]==wall){
            dp[0][j]=0;
        }
        else dp[0][j]=dp[0][j-1];
    }
    
    for(ll i=1;i<H;i++){
        for(ll j=1;j<W;j++){
            if(matrix[i][j]==wall){
                dp[i][j]=0;
            }
            else{
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
            dp[i][j] %= mod;
        }
    }
    
    cout<<dp[H-1][W-1];
    
    return 0;
}
