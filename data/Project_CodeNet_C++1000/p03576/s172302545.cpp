#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){

    ll N, K;
    cin >> N >> K;

    vector<ll> x(N), y(N);
    vector<pair<ll,ll>> xy(N);
    rep(i, 0, N){
        cin >> x[i] >> y[i];
        xy[i].first = x[i];
        xy[i].second = y[i];
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    ll ans = abs(x[N-1] - x[0]) * abs(y[N-1] - y[0]);

    rep(ix, 0, N-1){
        rep(iy, 0, N-1){
            rep(jx, ix+1, N){
                rep(jy, iy+1, N){
                    ll s = abs(x[jx] - x[ix]) * abs(y[jy] - y[iy]);
                    ll c = 0;
                    rep(i, 0, N){
                        if(x[ix] <= xy[i].first && xy[i].first <= x[jx] && y[iy] <= xy[i].second && xy[i].second <= y[jy]) c++;
                    }
                    if(c >= K) ans = min(ans, s);
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}