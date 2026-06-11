#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

vector<ll> a, acc;

int main(){

    // input
    ll n;
    cin >> n;
    a.resize(n);
    acc.resize(n+1, 0);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) acc[i+1] = acc[i] + a[i];

    ll ans = 1e18;
    rep(i, 0, n+1) {
       ll l = 0, r = i;
       while(r - l > 1) {
           ll m = l + (r - l) / 2;
           if(acc[m] >= acc[i] - acc[m]) r = m;
           else l = m;
       } 
       ll p = acc[l], q = acc[i] - acc[l];
       ll p2 = acc[r], q2 = acc[i] - acc[r];
       ll left_min = min(p, q), left_max = max(p, q);
       if(abs(p2-q2) < abs(p-q)) left_min = min(p2, q2), left_max = max(p2, q2);
        
        
       l = i, r = n;
       while(r - l > 1) {
           ll m = l + (r - l) / 2;
           if(acc[m] - acc[i] >= acc[n] - acc[m]) r = m;
           else l = m;
       } 
       ll rr = acc[l] - acc[i], s = acc[n] - acc[l];
       ll r2 = acc[r] - acc[i], s2 = acc[n] - acc[r];
       ll right_min = min(rr, s), right_max = max(rr, s);
       if(abs(r2-s2) < abs(rr-s)) right_min = min(r2, s2), right_max = max(r2, s2);

       ll tmp = max(left_max, right_max) - min(left_min, right_min);
       ans = min(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}