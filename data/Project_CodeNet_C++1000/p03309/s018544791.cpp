#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
    }
    vector<ll> v(n);
    rep(i,n) {
        v[i] = a[i] - i - 1;
    }
    sort(v.begin(),v.end());
    if(n % 2 != 0) {
        int h = (n - 1) / 2;
        int b = v[h];
        ll ans = 0;
        rep(i,n) {
            ans += abs(a[i] - b - i - 1);
        }
        cout << ans << endl;
        return 0;
    } else {
        int h = n / 2;
        int b1 = v[h];
        ll ans1 = 0;
        rep(i,n) {
            ans1 += abs(a[i] - b1 - i - 1);
        }
        int b2 = v[h-1];
        ll ans2 = 0;
        rep(i,n) {
            ans2 += abs(a[i] - b2 - i - 1);
        }
        cout << min(ans1,ans2) << endl;
        return 0;
    }
}