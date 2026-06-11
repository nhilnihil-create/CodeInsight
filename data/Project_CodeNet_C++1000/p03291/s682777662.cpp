#include<bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;

long long dp[100100][4]={};

int main(){
    string s; cin >> s;
    int N=s.size();
    dp[0][0]=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<4;j++){
            if(s[i]=='?'){
                dp[i+1][j]+=dp[i][j]*3%MOD;
            }else{
                dp[i+1][j]+=dp[i][j]%MOD;
            }
        }
        if(s[i]=='A'||s[i]=='?'){
            dp[i+1][1]+=dp[i][0]%MOD;
        }
        if(s[i]=='B'||s[i]=='?'){
            dp[i+1][2]+=dp[i][1]%MOD;
        }
        if(s[i]=='C'||s[i]=='?'){
            dp[i+1][3]+=dp[i][2]%MOD;
        }
    }
    cout << dp[N][3]%MOD << endl;
}