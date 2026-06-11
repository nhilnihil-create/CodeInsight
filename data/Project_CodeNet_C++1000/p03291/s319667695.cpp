#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;

ll dp[100005][4];
int main(){
    string S; cin>>S;
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=0;i<S.length();++i){
        for(int j=0;j<4;++j){
            if(S[i]!='?') (dp[i+1][j]+=dp[i][j])%=MOD;
            else (dp[i+1][j]+=dp[i][j]*3%MOD)%=MOD;
        }
        if(S[i]=='A'||S[i]=='?') (dp[i+1][1]+=dp[i][0])%=MOD;
        if(S[i]=='B'||S[i]=='?') (dp[i+1][2]+=dp[i][1])%=MOD;
        if(S[i]=='C'||S[i]=='?') (dp[i+1][3]+=dp[i][2])%=MOD;
    }
    cout<<dp[S.length()][3]<<endl;
    return 0;
}

