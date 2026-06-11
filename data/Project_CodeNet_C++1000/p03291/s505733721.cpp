#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    string S;  cin >> S;
    int N = S.length();
    ll mod = 1e9 + 7;
    vector<vector<ll>> dp(N+1, vector<ll>(4, 0));
    dp[N][3] = 1;
    for(int i=N-1; i>=0; i--) for(int j=3; j>=0; j--){
        dp[i][j] = ((S[i] == '?' ? 3 : 1)*dp[i+1][j])%mod;
        if(j < 3 && (S[i] == '?' || S[i] == "ABC"[j])){
            dp[i][j] += dp[i+1][j+1];
        }
        dp[i][j] %= mod;
    }
    cout << dp[0][0] << endl;
}
