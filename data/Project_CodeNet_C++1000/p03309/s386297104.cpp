#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) {
        ll tmp_a = 0;
        cin >> tmp_a;
        a[i] = tmp_a - ( i + 1 );
    }
    sort(a.begin(), a.end());
    ll b = 0;
    if ( n & 1 ) {
        b = a[n/2];
        ll ans = 0;
        for ( ll i = 0; i < n; i++ ) {
            ans += abs(a[i] - b);
        }
        cout << ans << endl;
        return 0;
    }
    else {
        ll b1 = a[n/2];
        ll b2 = a[n/2-1];
        ll ans1 = 0;
        ll ans2 = 0;
        for ( ll i = 0; i < n; i++ ) {
            ans1 += abs(a[i] - b1);
            ans2 += abs(a[i] - b2);
        }
        cout << min(ans1, ans2) << endl;
        return 0;
    }
}