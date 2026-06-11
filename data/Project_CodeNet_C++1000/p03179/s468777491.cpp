#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

/*
4
<><
*/


int n;
string s;
vector<vector<int> >dp;

void solve(){

    cin>>n>>s;
    dp.resize(n,vector<int>(n,0));

    if(s[n-2]=='>'){
        dp[n-1][0]=1;
        dp[n-1][1]=0;
    }
    if(s[n-2]=='<'){
        dp[n-1][1]=1;
        dp[n-1][0]=0;
    }
    for(int i=n-2;i>=1;i--){
        int total = n-i;
        for(int g = 0;g<=total;g++){
            if(g==0){
                if(s[i-1]=='<'){
                    dp[i][g]=0;
                }else{

                    for(int j=1;j<=total;j++){
                        dp[i][g] += dp[i+1][total-j];
                        dp[i][g] %=mod;
                    }
                }

            }else{

                if(s[i-1]=='>'){
                    dp[i][g] = (mod+ dp[i][g-1] - dp[i+1][g-1])%mod;
                }else{
                    dp[i][g] = dp[i][g-1] + dp[i+1][g-1];
                    dp[i][g] %=mod;
                }
            }
        }
    }
    long long ans =0;
    for(int i=1;i<=n;i++){
        ans += dp[1][n-i];
        ans %= mod;
    }
    cout<<ans<<"\n";
}

int main(){
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);

    cout.precision(10);
    int t=1;//cin>>t;
    while(t--){

        solve();
    }
    return 0;
}
