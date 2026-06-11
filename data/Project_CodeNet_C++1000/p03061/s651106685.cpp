#include<bits/stdc++.h>
#pragma optimize("Ofast")
using namespace std;

using ll = long long;
const int N = 1e5+5;

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    vector<ll> l(n),r(n);
    ll GCD = 0;
    for(int i = 0; i < n; ++i) {
        GCD = __gcd(GCD, a[i]);
        l[i] = GCD;
    }

    GCD = 0;
    for(int i = n-1; i >= 0; --i) {
        GCD = __gcd(GCD, a[i]);
        r[i] = GCD;
    }

    ll ans = 1;
    for(int i = 0; i < n; ++i) {
        if(i == 0) {
            ans = max(ans, r[1]);
            continue;
        }
        if(i == n-1) {
            ans = max(ans, l[n-2]);
            continue;
        }
        ans = max(ans, __gcd(l[i-1], r[i+1]));
    }
    cout << ans;
    return 0;
}
