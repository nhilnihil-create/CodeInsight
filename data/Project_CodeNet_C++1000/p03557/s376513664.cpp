#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    ll ans = 0;
    sort(a.begin(), a.end());
    sort(c.begin(), c.end());
    for (int i = 0; i < n; ++i) {
        ll upper = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        ll lower = c.end() - upper_bound(c.begin(), c.end(), b[i]);
        ans += upper * lower;
    }
    cout << ans << endl;

    return 0;
}
