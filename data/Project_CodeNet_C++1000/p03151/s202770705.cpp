#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    cin >> n;
    int a[n], b[n];
    rep(i, n) {
        cin >> a[i];
    }
    rep(i, n) cin >> b[i];
    ll diff[n];
    rep(i, n) diff[i] = a[i] - b[i];
    sort(diff, diff + n);
    int ans = 0;
    ll sum = 0;

    rep(i, n) {
        if (diff[i] < 0) {
            sum += diff[i];
            ans++;
        } else
            break;
    }
    int i = n;
    while (sum < 0) {
        i--;
        if (diff[i] > 0) {
            sum += diff[i];
            ans++;
        } else {
            ans = -1;
            break;
        }
    }
    cout << ans << endl;
}
