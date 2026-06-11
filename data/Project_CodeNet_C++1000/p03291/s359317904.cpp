#include<iostream>
#include<math.h>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

string S;
ll dp[100010][4]={};
int main(){
    cin>>S;
    ll ans=0;
    dp[0][0]=1;
    for(ll i=0;i<S.length();i++){
        for(ll j=0;j<4;j++){
          dp[i+1][j]=(dp[i+1][j]+dp[i][j]*(S[i]=='?'?3:1))%MOD;
        }
        if(S[i]=='A' || S[i]=='?'){
          dp[i+1][1]=(dp[i+1][1]+dp[i][0])%MOD;
        }
        if(S[i]=='B' || S[i]=='?'){
          dp[i+1][2]=(dp[i+1][2]+dp[i][1])%MOD;
        }
        if(S[i]=='C' || S[i]=='?'){
          dp[i+1][3]=(dp[i+1][3]+dp[i][2])%MOD;
        }
    }
    cout<<dp[S.length()][3]<<endl;
    return 0;
}