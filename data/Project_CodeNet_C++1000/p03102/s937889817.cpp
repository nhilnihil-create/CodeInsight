#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n, m, c;
    cin >> n >> m >> c;
    ll ans = 0;
    vector<ll> b(m);
    rep(i, 0, m) cin >> b[i];
    rep(i, 0, n) {
        ll tmp = c;
        rep(j, 0, m){
            ll a;
            cin >> a;
            tmp += a * b[j];
        }
        if(tmp > 0) ans++;
    }
    cout << ans << endl;
    return 0;
}