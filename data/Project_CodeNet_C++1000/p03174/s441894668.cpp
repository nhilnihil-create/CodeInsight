#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9;
const int MAX_V = 10000;
typedef pair<int, int>P;
#define MOD 1000000007
int N, A[21][21];
ll dp[22][1 << 21];
//---------------------------------------------------------------------------------------------------
int main() {
    cin >> N;
    rep(i,N) rep(j,N) cin >> A[i][j];
    rep(i,N){rep(j,(1<<N)-1){dp[i][j]=0ll;}}
    dp[0][0] = 1;
    rep(i,N) rep(msk,1 << N) if(i == __builtin_popcount(msk)) {
        rep(j,N) if (!(msk & (1 << j))) if (A[i][j]) {
            dp[i+1][msk | (1 << j)] += dp[i][msk];
          dp[i+1][msk | (1 << j)]%=MOD;
        }
    }
    dp[N][(1<<N)-1]+=MOD;
    dp[N][(1<<N)-1]%=MOD;
    cout << dp[N][(1 << N) - 1] << endl;
}