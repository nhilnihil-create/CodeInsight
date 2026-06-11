#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e8;
const ll INF = 1e16;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    string S;
    cin >> S;
    int N = S.size();
    ll dp[N+1][4];
    fill(dp[0], dp[N+1], 0);
    dp[0][0] = 1;
    rep(i, N){
        if(S[i] == 'A' || S[i] == '?'){
            dp[i+1][0] += dp[i][0];
            dp[i+1][1] += dp[i][1] + dp[i][0];
            dp[i+1][2] += dp[i][2];
            dp[i+1][3] += dp[i][3];
        }
        if(S[i] == 'B' || S[i] == '?'){
            dp[i+1][0] += dp[i][0];
            dp[i+1][1] += dp[i][1];
            dp[i+1][2] += dp[i][2] + dp[i][1];
            dp[i+1][3] += dp[i][3];
        }
        if(S[i] == 'C' || S[i] == '?'){
            dp[i+1][0] += dp[i][0];
            dp[i+1][1] += dp[i][1];
            dp[i+1][2] += dp[i][2];
            dp[i+1][3] += dp[i][3] + dp[i][2];
        }
        rep(j, 4){
            dp[i+1][j] %= MOD;
        }
    }
    cout << dp[N][3] << endl;
}