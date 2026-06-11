#include<bits/stdc++.h>
using namespace std;

long long int dp[100005][4];
const long long int mod=1e9+7;
int main(){
    string S;
    cin >> S;
    long long int ans=0;
    dp[0][0]=1;
    for(int i=0;i<S.length();i++){
        if(S[i]=='A'){
            for(int j=0;j<4;j++)(dp[i+1][j] += dp[i][j])%=mod;
            (dp[i+1][1] += dp[i][0])%=mod;
        }
        else if(S[i]=='B'){
            for(int j=0;j<4;j++)(dp[i+1][j] += dp[i][j])%=mod;
            (dp[i+1][2] += dp[i][1])%=mod;
        }
        else if(S[i]=='C'){
            for(int j=0;j<4;j++)(dp[i+1][j] += dp[i][j])%=mod;
            (dp[i+1][3] += dp[i][2])%=mod;
        }
        else{
            for(int j=0;j<4;j++){
                (dp[i+1][j] += 3 * dp[i][j])%=mod;
                if(j<3)(dp[i+1][j+1] += dp[i][j])%=mod;
            }
        }
    }
    cout << dp[S.length()][3] << endl;
}