#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n, m;
    cin >> n >> m;
    vector<bool> ok(m, true);
    rep(i, 0, n) {
        ll k;
        cin >> k;
        vector<bool> tmp(m, false);
        rep(j, 0, k) {
            ll a;
            cin >> a;
            a--;
            tmp[a] = true;
        }
        rep(j, 0, m) {
            if(!tmp[j]) ok[j] = false;
        }
    }
    ll ans = 0;
    rep(i, 0, m) {
        if(ok[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}