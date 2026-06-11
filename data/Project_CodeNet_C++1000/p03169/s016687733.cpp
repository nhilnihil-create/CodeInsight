#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using stkll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif

double dp[310][310][310];

int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    ll N; cin >> N;
    vll cnt(4, 0);
    rep(i, N) {
        ll a;
        cin >> a;
        cnt[a]++;
    }

    for(ll i = 0; i <= N; i++) {
        for(ll j = 0; j <= N; j++) {
            for(ll k = 0; k <= N; k++) {
                double s = i + j + k;
                if(s == 0) {
                    dp[i][j][k] = 0;
                    continue;
                }
                dp[i][j][k] += (double)N / s;
                if(i-1 >= 0) dp[i][j][k] += dp[i-1][j+1][k] * i / s;
                if(j-1 >= 0) dp[i][j][k] += dp[i][j-1][k+1] * j / s;
                if(k-1 >= 0) dp[i][j][k] += dp[i][j][k-1] * k / s;
            }
        }
    }
    cout << dp[cnt[3]][cnt[2]][cnt[1]] << endl;
}
