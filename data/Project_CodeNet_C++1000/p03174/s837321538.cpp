#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<(int)n;i++)
const ll INF = (1LL<<60);
const int MOD = 1000000007;

int n;
ll a[30][30];
ll dp[1<<21];

int main(){
    cin >> n;
    rep(i,n){
        rep(j,n){
            cin >> a[i][j];
        }
    }

    dp[0] = 1;
    for(int S=1;S < 1<<n; S++){
        int i = __builtin_popcount(S);
        rep(j,n){
            if((S>>j) & 1 && a[i-1][j]){
                dp[S] = (dp[S] + dp[S^(1<<j)]) % MOD;
            }
        }
    }

    cout << dp[(1<<n)-1] << endl;
}