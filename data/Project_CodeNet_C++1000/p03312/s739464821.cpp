#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 1000000000000009;

int main()
{
    int n;
    cin >> n;
    ll a[200005];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll s[200005];
    s[0] = 0;
    ll ans = INF;
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i - 1];
    for(int i = 2; i < n - 1; i++){
        ll l = lower_bound(s + 1, s + i - 1, (s[i] + 1) / 2) - s;
        ll lmax = max(s[l], s[i] - s[l]), lmin = min(s[l], s[i] - s[l]);
        if(l > 1){
            lmax = min(lmax, max(s[l - 1], s[i] - s[l - 1]));
            lmin = max(lmin, min(s[l - 1], s[i] - s[l - 1]));
        }
        ll r = lower_bound(s + i + 1, s + n - 1, (s[n] + s[i] + 1) / 2) - s;
        ll rmax = max(s[r] - s[i], s[n] - s[r]), rmin = min(s[r] - s[i], s[n] - s[r]);
        if(r > i + 1){
            rmax = min(rmax, max(s[r - 1] - s[i], s[n] - s[r - 1]));
            rmin = max(rmin, min(s[r - 1] - s[i], s[n] - s[r - 1]));
        }
        ans = min(ans, max(lmax, rmax) - min(lmin, rmin));
    }
    cout << ans << endl;
}
