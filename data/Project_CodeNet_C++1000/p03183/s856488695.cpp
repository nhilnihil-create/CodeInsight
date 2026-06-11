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

ll dp[1100][22000];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N; cin >> N;
    vll w(N), s(N), v(N);
    vector<pll> vec;
    rep(i,N) {
        cin >> w[i] >> s[i] >> v[i];
        vec.emplace_back(w[i]+s[i], i);
    }
    sort(vec.begin(), vec.end());

    for(ll i = 1; i <= N; i++) {
        ll idx = vec[i-1].second;
        rep(j, 22000) {
            dp[i][j] = dp[i-1][j];
            if(j-w[idx] >= 0 && j-w[idx] <= s[idx]) chmax(dp[i][j], dp[i-1][j-w[idx]] + v[idx]);
        }
    }
    ll ans = 0;
    rep(j, 22000) chmax(ans, dp[N][j]);
    cout << ans << endl;
}
