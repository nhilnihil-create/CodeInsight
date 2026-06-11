#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll h, w;
    cin >> h >> w;
    vector< vector<ll> > d(10, vector<ll> (10));
    rep(i, 0, 10) {
        rep(j, 0, 10) cin >> d[i][j];
    }
    rep(i, 0, 10){
        rep(j, 0, 10){
            rep(k, 0, 10){
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }
    ll ans = 0;
    rep(i, 0, h){
        rep(j, 0, w) {
            ll a;
            cin >> a;
            if(a == -1) continue;
            ans += d[a][1];
        }
    }
    cout << ans << endl;
    return 0;
}