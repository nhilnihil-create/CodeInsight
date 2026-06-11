#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

int main(){
    ll D, G;
    cin >> D >> G;
    G /= 100;
    vector<ll> p(D), c(D);
    VVL dp(D+10, VL(1010, 0));
    rep(i, 0, D){
        cin >> p[i] >> c[i];
        c[i] /= 100;
    }

    rep(i, 0, D){
        rep(k, 1, 1001){
            rep(j, 1, p[i]){
                if(k-j >= 0) dp[i+1][k] = max(dp[i][k], dp[i][k-j] + j*(i+1));
            }
            if(k-p[i] >= 0) dp[i+1][k] = max(dp[i][k], dp[i][k-p[i]] + p[i]*(i+1) + c[i]);
        }
    }
    ll ans = 1e18;
    rep(i, 0, 1001){
        if(dp[D][i] >= G) ans = min(ans, i);
    }
    cout << ans << endl;
    cerr << dp[D][ans] << endl;
    return 0;
}