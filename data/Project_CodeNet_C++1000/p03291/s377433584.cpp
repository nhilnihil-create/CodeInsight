#include<iostream>
#include<string>
#include<cstring>
using namespace std;

const int MOD=1000000007;
string S;
void add(long long &a,long long b){
    a+=b;
    if(a>=MOD)a-=MOD;
}
long long dp[210000][5];
int main(){
    cin>>S;
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=0;i<S.size();i++){
        for(int j=0;j<5;j++){
            if(S[i]!='?')add(dp[i+1][j],dp[i][j]);
            else add(dp[i+1][j],dp[i][j]*3%MOD);

        }
        if(S[i]=='A'||S[i]=='?')add(dp[i+1][1],dp[i][0]);
        if(S[i]=='B'||S[i]=='?')add(dp[i+1][2],dp[i][1]);
        if(S[i]=='C'||S[i]=='?')add(dp[i+1][3],dp[i][2]);
    }
    cout<<dp[S.size()][3]<<endl;
    }