#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

ll gcd(ll a, ll b){
    if(a < b) return gcd(b, a);
    ll r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

ll lcm(ll a, ll b){
    ll ret = a / gcd(a,b) * b;
    return ret;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n), left(n), right(n);
    rep(i, 0, n) cin >> a[i];
    left[0] = a[0]; right[n-1] = a[n-1];
    rep(i, 1, n) left[i] = gcd(a[i], left[i-1]);
    for(ll i = n-2; i >= 0; i--) right[i] = gcd(a[i], right[i+1]);
    ll ans = right[1];
    rep(i, 1, n-1) ans = max(ans, gcd(left[i-1], right[i+1]));
    ans = max(ans, left[n-2]);
    cout << ans << endl;
    return 0;
}