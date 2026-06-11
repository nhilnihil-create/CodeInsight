#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = LLONG_MAX;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    string S;
    int K;
    cin >> S >> K;
    int N = S.size();
    int dp[N][N][K+1];
    rep(i, K+1){
        rep(j, 2*i+1){
            rep(k, N-j){
                dp[k][k+j][i] = j+1;
            }
        }
        rep2(j, 2*i+1, N-1){
            rep(k, N-j){
                if(S[k] == S[k+j]){
                    if(j == 1 && i == 0) dp[k][k+j][i] = 2;
                    else dp[k][k+j][i] = dp[k+1][k+j-1][i]+2;
                }
                else{
                    dp[k][k+j][i] = max(dp[k+1][k+j][i], dp[k][k+j-1][i]);
                    if(i > 0){
                        dp[k][k+j][i] = max(dp[k][k+j][i], dp[k+1][k+j-1][i-1]+2);
                    }
                }
            }
        }
    }
    cout << dp[0][N-1][K] << endl;
}