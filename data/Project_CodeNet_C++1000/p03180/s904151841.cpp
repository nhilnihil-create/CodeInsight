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
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

ll dp[1<<16], cost[1<<16];

int main() {
    ll N;
    cin >> N;
    vvll a(N, vll(N));
    rep(i, N) rep(j, N) cin >> a[i][j];
    rep(bit, 1<<N) {
        rep(i, N) {
            if(!(bit>>i&1)) continue;
            rep(j, N) {
                if(!(bit>>j&1)) continue;
                if(i >= j) continue;
                cost[bit] += a[i][j];
            }
        }
    }

    dp[0] = 0;
    for(ll bit = 1; bit < 1<<N; bit++) {
        for(ll t = bit; t > 0; t = (t-1)&bit) {
            chmax(dp[bit], dp[bit - t] + cost[t]);
        }
    }
    cout << dp[(1<<N)-1] << endl;
}
