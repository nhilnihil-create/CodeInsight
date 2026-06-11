#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cmath>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i,i0,n) for(int (i)=(i0);(i)<(n);(i)++)
#define rn return
typedef std::pair<int,int> P;
using namespace std;
using ll = long long;




int main(){
    string S;
    cin >> S;
    int N = S.size();
    int MOD = 1000000007;
    
    long long dp[100010][4] = {};
    
    dp[0][0] = 1LL;
    FOR(i,1,N+1){
        
        if (S[i-1] == '?'){
            dp[i][1] = dp[i-1][1]*3LL + dp[i-1][0];
            dp[i][2] = dp[i-1][2]*3LL+ dp[i-1][1];
            dp[i][3] = dp[i-1][3]*3LL+ dp[i-1][2];
            dp[i][0] = dp[i-1][0]*3LL;
        }
        if (S[i-1] == 'A'){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1]+ dp[i-1][0];
            dp[i][2] = dp[i-1][2];
            dp[i][3] = dp[i-1][3];
        }
        if (S[i-1] == 'B'){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][2]+ dp[i-1][1] ;
            dp[i][3] = dp[i-1][3];
        }
        if (S[i-1] == 'C'){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][2];
            dp[i][3] = dp[i-1][3]+ dp[i-1][2];
        }
        rep(j,4) dp[i][j] %= MOD;
    }
    cout << dp[N][3]%MOD << endl;
    rn 0;
}