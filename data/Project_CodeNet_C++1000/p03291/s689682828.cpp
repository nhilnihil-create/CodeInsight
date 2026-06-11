#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const ll BIG=1e15;

ll dp[4][100001];
int main(){
    string S;
    cin>>S;
    dp[3][0]=1;
    for(int i=0;i<S.size();i++){
        for(int j=0;j<4;j++) dp[j][i+1]=dp[j][i];
        if(S.at(i)=='A') dp[0][i+1]+=dp[3][i];
        if(S.at(i)=='B') dp[1][i+1]+=dp[0][i];
        if(S.at(i)=='C') dp[2][i+1]+=dp[1][i];
        if(S.at(i)=='?') {
            dp[0][i+1]=dp[0][i]*3+dp[3][i];
            dp[1][i+1]=dp[1][i]*3+dp[0][i];
            dp[2][i+1]=dp[2][i]*3+dp[1][i];
            dp[3][i+1]=dp[3][i]*3;
        }
        for(int j=0;j<4;j++) {dp[j][i+1]=(dp[j][i+1])%mod; }
        
    }

    cout<<dp[2][S.size()]<<endl;
}