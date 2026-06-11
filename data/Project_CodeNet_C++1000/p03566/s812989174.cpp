#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int N;
long double t[110], v[110], lim[110];

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N;
    rep(i, N) cin >> t[i];
    rep(i, N) cin >> v[i];
    for (int i=N-2; i>=0; i--) lim[i] = min({lim[i+1]+t[i+1], v[i], v[i+1]});
    double ans = 0, now_spe = 0;
    rep(i, N) {
        if (now_spe+t[i]<lim[i]) {
            ans += (2*now_spe+t[i])*t[i]/2.0;
            now_spe += t[i];
        }
        else {
            double max_spe = min(v[i], (t[i]+lim[i]+now_spe)/2);
            ans += (now_spe+max_spe)*(max_spe-now_spe)/2;
            ans += (lim[i]+max_spe)*(max_spe-lim[i])/2;
            ans += max_spe*(t[i]-(max_spe-now_spe)-(max_spe-lim[i]));
            now_spe = lim[i];
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
}