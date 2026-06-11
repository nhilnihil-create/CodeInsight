#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;
int mod = 1000000007;

void solve();

int main(void){
    int N; cin >> N;
    int C[N+1] = {}; rep(i, N) cin >> C[i+1];
    ll dp[N+1][2];
    int prev_c[200001] = {}; //prev_c[i]: 色iが一番最近に現れた場所

    dp[0][0] = 0; dp[0][1] = 0; dp[1][0] = 1; dp[1][1] = 0; prev_c[C[1]] = 1;
    for(int i = 2; i <= N; i++){
        
        //dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % mod;
        //dp[i][1] = (dp[prev_c[C[i]]][0] + dp[prev_c[C[i]]][1]) % mod;
        //基本はこの遷移でいいけど、隣接してる時が危ない -> 1個前をそのままコピーすればいい
        if(C[i] == C[i-1]){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
        }
        else{
            dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % mod;
            dp[i][1] = (dp[prev_c[C[i]]][0] + dp[prev_c[C[i]]][1]) % mod;
        }
        
        prev_c[C[i]] = i;
    }
    cout << (dp[N][0] + dp[N][1]) % mod << endl;
    return 0;
}

void solve(){}