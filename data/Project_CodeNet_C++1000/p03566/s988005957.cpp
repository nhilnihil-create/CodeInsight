#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

ll N,T;
double INF=20000.0 * 10.0;

signed main() {
    cin>>N;
    vector<ll> t(N),v(N);
    rep(i,0,N){ cin>>t[i]; T+=t[i]; }
    rep(i,0,N){ cin>>v[i]; }
    vector<double> maxv(2*T+1, INF);// maxv[t]: 時刻t/2における速度

    maxv[0] = 0.0;
    rep(p,0,maxv.size()) maxv[p] = min(maxv[p], 0.0 + 0.5 * p);

    rep(p, 2*T, maxv.size()) maxv[p] = 0.0;
    rep(p,0,2*T) maxv[p] = min(maxv[p], 0.0 + 0.5 * (2*T-p));

    ll l = 0;
    rep(i,0,N){
        ll r = l + t[i]*2;
        rep(p, 0, l){
            maxv[p] = min(maxv[p], (double)v[i] + 0.5 * (l-p));
        }
        rep(p, l, r) {
            maxv[p] = min(maxv[p], (double)v[i]);
        }
        rep(p, r, maxv.size()){
            maxv[p] = min(maxv[p], (double)v[i] + 0.5 * (p-r));
        }
        l = r;
    }

    // rep(p, 0, maxv.size()){
    //     printf("%.1f - %.1f\n", p*0.5, maxv[p]);
    // }

    double ans = 0.0;
    rep(p, 1, maxv.size()){
        ans += maxv[p] + maxv[p-1];
    }
    ans /= 4;
    printf("%.5f\n",ans);

    return 0;
}
