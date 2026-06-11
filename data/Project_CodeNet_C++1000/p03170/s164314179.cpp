#include <bits/stdc++.h>
using namespace std;

const long long int MOD = 1e9+7;
#define pb push_back
typedef long long ll;
const long long int N = 1e5;



int main(){
    int n,k;
    cin>>n>>k;
    int a[n+5];
    vector<bool> dp(k+5,false);
    // vector<vector<bool>> dp(k+5,vector<bool>(n+5,false));
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[0]=false;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(a[j]<=i){
                dp[i]= dp[i] || !dp[i-a[j]];
            }
        }
    }
    if(dp[k]) cout<<"First";
    else cout<<"Second";

    return 0;
}