#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    int a[n];
    rep(i,n) cin >> a[i];
    float ave = accumulate(a, a+n, 0) / (float)n;
    int ans = n;
    float min_diff = 1001001001;
    rep(i,n) {
        if (abs(a[n-i-1] - ave) <= min_diff) {
            min_diff = abs(a[n-i-1] - ave);
            ans = n-i-1;
        }
    }
    cout << ans << endl;
}