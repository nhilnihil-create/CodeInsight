#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main() {
    ll n,ans;
    vector<ll> a(5);
    ll m;

    cin >> n;
    rep(i, 5) {
        cin >> a[i];
    }
    m = a[0];
    for (int i = 1;i < 5;++i) {
        if (m > a[i])
            m = a[i];
    }

    if (n == (n / m) * m)
        ans = n / m;
    else
        ans = n / m + 1;
    ans += 4;

    cout << ans << endl;

    return 0;
}
