#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll neg = 0;
    rep(i, 0, n){
        cin >> a[i];
        if(a[i] < 0) neg++;
    }
    if(neg % 2 == 1){
        ll ans = 0, mn = 1e18;
        rep(i, 0, n){
            ans += abs(a[i]);
            mn = min(mn, abs(a[i]));
        }
        cout << ans - 2*mn << endl;
    } else {
        ll ans = 0;
        rep(i, 0, n) ans += abs(a[i]);
        cout << ans << endl;
    }
    return 0;
}