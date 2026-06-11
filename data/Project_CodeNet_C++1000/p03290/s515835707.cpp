#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int D, G;
int p[12], c[12];

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> D >> G;
    rep(i, D) cin >> p[i] >> c[i];
    
    int ans = 100000;
    rep(S, 1<<D) {
        int ans_cand = 0;
        int now = 0;
        rep(i, D) {
            if ((S>>i)&1) {
                ans_cand += p[i];
                now += 100*(i+1)*p[i]+c[i];
            }
        }
        if (now>=G) {
            ans = min(ans, ans_cand);
            continue;
        }
        for (int i=D-1; i>=0; i--) {
            if (!((S>>i)&1)) {
                if (now+100*(i+1)*(p[i]-1)<=G) {
                    ans_cand += p[i]-1;
                    now += 100*(i+1)*(p[i]-1);
                }
                else {
                    int need = (G-now)/(100*(i+1));
                    ans_cand += need;
                    now += 100*(i+1)*need;
                }
            }
        }
        if (now>=G) ans = min(ans, ans_cand);
    }
    cout << ans << endl;
}