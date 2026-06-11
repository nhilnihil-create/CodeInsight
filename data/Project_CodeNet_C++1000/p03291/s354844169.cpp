#include <bits/stdc++.h>

#include <math.h>
#include <stdlib.h>


#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true; } return false; }

//INT_MAX	2,147,483,647 = 2*1.0e9

const ll mod = 1000000007;

int main(){
    string S; cin >> S;

    ll dp[100010][2][2][2];
    for(int i = 0; i < 100010; i++) for(int j = 0; j < 2; j++) for(int k = 0; k < 2; k++) for(int l = 0; l < 2; l++) dp[i][j][k][l] = 0;
    dp[0][0][0][0] = 1;
    
    for(int i = 0; i < S.length(); i++){
        if(S[i] == 'A' || S[i] == '?'){
            for(int k = 0; k < 2; k++){
                for(int l = 0; l < 2; l++){
                    dp[i+1][0][k][l] += dp[i][0][k][l];
                    dp[i+1][0][k][l] %= mod;
                    dp[i+1][1][k][l] += dp[i][0][k][l];
                    dp[i+1][1][k][l] %= mod;
                    dp[i+1][1][k][l] += dp[i][1][k][l];
                    dp[i+1][1][k][l] %= mod;
                }
            }
        }

        if(S[i] == 'B' || S[i] == '?'){
            for(int l = 0; l < 2; l++){
                for(int k = 0; k < 2; k++){
                    dp[i+1][0][k][l] += dp[i][0][k][l];
                    dp[i+1][0][k][l] %= mod;
                }
                dp[i+1][1][0][l] += dp[i][1][0][l];
                dp[i+1][1][0][l] %= mod;
                dp[i+1][1][1][l] += dp[i][1][0][l];
                dp[i+1][1][1][l] %= mod;
                dp[i+1][1][1][l] += dp[i][1][1][l];
                dp[i+1][1][1][l] %= mod;
            }
        }

        if(S[i] == 'C' || S[i] == '?'){
            for(int l = 0; l < 2; l++){
                for(int k = 0; k < 2; k++){
                    dp[i+1][0][k][l] += dp[i][0][k][l];
                    dp[i+1][0][k][l] %= mod;
                }
                dp[i+1][1][0][l] += dp[i][1][0][l];
                dp[i+1][1][0][l] %= mod;
            }
            dp[i+1][1][1][0] += dp[i][1][1][0];
            dp[i+1][1][1][0] %= mod;
            dp[i+1][1][1][1] += dp[i][1][1][0];
            dp[i+1][1][1][1] %= mod;
            dp[i+1][1][1][1] += dp[i][1][1][1];
            dp[i+1][1][1][1] %= mod;
        }
    }

    cout << dp[S.length()][1][1][1] << endl;

    return 0;
}
