#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int main() {
    int n,m; cin >> n >> m;
    lint x[1000],y[1000],z[1000];
    rep(i,n) cin >> x[i] >> y[i] >> z[i];
    lint ans = 0;
    rep(i,2) {
        rep(j,2) {
            rep(k,2) {
                lint t[1000] = {0};
                rep(u,n) {
                    lint value = 0;
                    if (i*2-1 > 0) value += x[u];
                    else value -= x[u];
                    if (j*2-1 > 0) value += y[u];
                    else value -= y[u];
                    if (k*2-1 > 0) value += z[u];
                    else value -= z[u];
                    
                    t[u] = value;
                }
                sort(t, t+n, greater<lint>());
                lint value = 0;
                rep(i,m) value += t[i];
                ans = max(ans, value);
            }
        }
    }
    cout << ans << endl;
    // WAwakaranai...
}