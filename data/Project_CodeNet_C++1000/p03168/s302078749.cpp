#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int N; cin >> N;
    vector<double> p(N);
    rep(i, N) cin >> p[i];
    vector<vector<double>> dp(N+1, vector<double>(N+1));
    dp[0][0] = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= i; j++){
            dp[i+1][j+1] += dp[i][j] * p[i];
            dp[i+1][j] += dp[i][j] * (1-p[i]);
        }
    }
    int half = N/2 + 1;
    double ans = 0;
    rep(i, N+1){
        if(half > i) continue;
        ans += dp[N][i];
    }
    printf("%.10f", ans);
    cout << endl;
    return 0;
}
