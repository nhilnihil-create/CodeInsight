#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < n; ++i)

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) cin >> c[i];
    sort(a.begin(), a.end());
    sort(c.begin(), c.end());

    // b[i]より小さい要素がaに何個あるか
    int aa = 0;
    // b[i]より大きい要素がcに何個あるか
    int cc = 0;
    long long ans = 0;
    rep(i,n) {
        aa = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        cc = c.end() - upper_bound(c.begin(), c.end(), b[i]);
        ans += (long long)aa * cc;
    }
    cout << ans << endl;
    return 0;
}