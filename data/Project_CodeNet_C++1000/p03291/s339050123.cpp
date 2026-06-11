#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(ll i=0;i<(ll)n;i++)

const ll MOD = 1e9+7;

ll dp[100010][4];

int main(){
    string s ; cin >> s;
    int n=s.size();
    for(int i=n;i>=0;i--){
        for(int j=3;j>=0;j--){
            if(i==n){
                if(j==3) dp[i][j] = 1;
                else dp[i][j] = 0;
            }else{
                if(s[i]=='?') dp[i][j] = 3 * dp[i+1][j];
                else dp[i][j] = dp[i+1][j];
                if(j < 3 && (s[i]=='?'|| s[i] == "ABC"[j]) ){
                    dp[i][j] += dp[i+1][j+1];
                }
            }
            dp[i][j] %= MOD;
        }
    }
    cout << dp[0][0] << endl;
}