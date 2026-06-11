#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll dp[3000][3002];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int N;
    string S;
    cin >> N >> S;
    dp[0][1] = 1;
    dp[0][N+1] = -1;
    for(int i = 0; i < N-1; i++){
        for(int j = 1; j <= N; j++){
            dp[i][j] += dp[i][j-1];
            dp[i][j] %= MOD;
        }
        if(S[i] == '>'){
            for(int j = 1; j <= N-i; j++){
                dp[i+1][1] += dp[i][j];
                dp[i+1][1] %= MOD;
                dp[i+1][j] -= dp[i][j];
                dp[i+1][j] += MOD;
                dp[i+1][j] %= MOD;
            }
        }else{
            for(int j = 1; j <= N-i; j++){
                dp[i+1][j] += dp[i][j];
                dp[i+1][j] %= MOD;
                dp[i+1][N-i] -= dp[i][j];
                dp[i+1][N-i] += MOD;
                dp[i+1][N-i] %= MOD;
            }
        }
    }
    // for(int i = 0; i < N; i++){
    //     for(int j = 1; j <= N-i; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << dp[N-1][1] << endl;
}