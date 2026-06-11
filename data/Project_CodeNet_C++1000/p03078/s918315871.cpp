#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    rep(i, 0, x) cin >> a[i];
    rep(i, 0, y) cin >> b[i];
    rep(i, 0, z) cin >> c[i];
    vector<ll> d(x*y);
    rep(i, 0, x){
        rep(j, 0, y){
            d[i*y + j] = a[i] + b[j];
        }
    }
    sort(d.begin(), d.end(), greater<ll>());
    vector<ll> e(min(x*y,k)*z);
    rep(i, 0, min(x*y,k)){
        rep(j, 0, z){
            e[i*z+j] = d[i] + c[j];
        }
    }
    sort(e.begin(), e.end(), greater<ll>());
    rep(i, 0, k) cout << e[i] << "\n";
    return 0;
}