#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n; cin >> n;
    vector<pair<ll,ll>> r(n), b(n);
    rep(i, 0, n) cin >> r[i].first >> r[i].second;
    rep(i, 0, n) cin >> b[i].first >> b[i].second;

    sort(b.begin(), b.end());

    vector<bool> used(n, false);
    ll ans = 0;

    rep(i, 0, n){
        ll bx = b[i].first;
        ll by = b[i].second;
        ll target = -1, mx = -1;
        rep(j, 0, n){
            ll rx = r[j].first;
            ll ry = r[j].second;
            if(!used[j] && rx < bx && ry < by){
                if(ry > mx){
                    mx = ry;
                    target = j;
                }
            }
        }
        if(mx != -1){
            used[target] = true;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
