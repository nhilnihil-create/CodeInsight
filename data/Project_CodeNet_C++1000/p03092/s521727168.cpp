#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

const ll inf = (ll)2e16;
const ll maxn = (ll)5e3 + 10;

ll dp[maxn];
ll inv[maxn];
ll p[maxn];
ll n, a, b;


void solve(){
    fill(dp, dp + maxn, inf);
    cin >> n >> a >> b;
    for(ll i = 0; i < n; ++i){
        cin >> p[i];
        p[i]--;
    }
    p[n] = n;
    for(ll i = 0; i <= n; ++i){
        inv[p[i]] = i;
    }
    for(ll i = 0; i <= n; ++i){
        ll adda = 0, addb = 0;
        for(ll j = p[i] - 1; j >= -1; --j){
            if(j == -1){
                dp[i] = min(dp[i], adda * a + addb * b);
                continue;
            }
            dp[i] = min(dp[i], dp[inv[j]] + adda * a + addb * b);
            if(j != p[i]){
                if(inv[j] < i){
                    adda++;
                } else if(inv[j] > i) {
                    addb++;
                }
            }
        }
    }
    cout << dp[n] << "\n";
}

signed main(){
    srand(time(0));
    ll t = 1;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else

    #endif// DEBUG
    while(t--){
        solve();
    }
}
