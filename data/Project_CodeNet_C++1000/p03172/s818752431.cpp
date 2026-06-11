#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<(int)n;i++)
const ll INF = (1LL<<60);
const int MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int N,K;
vector<int> a(110);
vector<vector<ll> > dp(110,vector<ll>(100010,0));

int main(){
    cin >> N >> K;
    rep(i,N){
        cin >> a[i];
    }

    vector<ll> sum(100010,0);
    dp[0][0] = 1;
    for(int i=0;i<N;i++){
        sum[0] = 0;
        for(int j=0;j<=K;j++) sum[j+1] = (sum[j] + dp[i][j]) % MOD;
        for(int j=0;j<=K;j++) dp[i+1][j] = (sum[j+1] - sum[max(0, j-a[i])] + MOD) % MOD;
    }
    cout << dp[N][K] << endl;
}