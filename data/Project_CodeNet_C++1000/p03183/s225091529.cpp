#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
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

// 最高で10^4 * 2 くらいまでは重くなりうる
ll dp[1100][21000];

int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    ll N;
    cin >> N;
    vll w(N+1), s(N+1), v(N+1);
    vpll vec;
    for(int i = 1; i <= N; i++) {
        cin >> w[i] >> s[i] >> v[i];
        vec.emplace_back(w[i] + s[i], i);
    }
    sort(vec.begin(), vec.end());
    for(int i = 1; i <= N; i++) {
        int idx = vec[i-1].second;
        ll wi = w[idx], vi = v[idx], si = s[idx];
        for(ll j = 0; j <= 21000; j++) {
            chmax(dp[i][j], dp[i-1][j]);
            if(j-wi >= 0 && j-wi <= si) chmax(dp[i][j], dp[i-1][j-wi] + vi);
        }
    }
    ll ans = 0;
    rep(i, 21000) chmax(ans, dp[N][i]);
    cout << ans << endl;
}
