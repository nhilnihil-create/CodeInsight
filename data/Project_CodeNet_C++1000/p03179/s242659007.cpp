#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;
const ll LINF=(ll)1e18;

ll dp[3001][3001];

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    dp[0][0]=1;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<=i;j++){
            if(s[i]=='>'){
                dp[i+1][0]+=dp[i][j];
                dp[i+1][j+1]-=dp[i][j];
            }
            else{
                dp[i+1][j+1]+=dp[i][j];
                dp[i+1][i+2]-=dp[i][j];
            }
        }
        dp[i+1][0]%=MOD;
        for(int j=1;j<n;j++){
            dp[i+1][j]=(dp[i+1][j]+dp[i+1][j-1])%MOD;
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=dp[n-1][i];
    }
    ans%=MOD;
    ans=(ans+MOD)%MOD;
    cout<<ans<<endl;
}