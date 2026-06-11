#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5,mod=1e9+7;
ll dp[N][4],n,ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;cin>>s;
    n=s.size();
    dp[n][3]=1;
    for(ll i=n-1;i>=0;i--){
        for(ll j=3;j>=0;j--){
            dp[i][j] = dp[i+1][j]*(s[i]=='?'?3ll:1ll);
            if(j<3 && (s[i]=='?' || s[i]=="ABC"[j]))dp[i][j]+=dp[i+1][j+1];
            dp[i][j]%=mod;
        }
    }
    cout<<dp[0][0];
}