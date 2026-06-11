#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    int n, ans = 0, cnt = 0;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        if (a[i - 1] == a[i]) {
            cnt++;
            if (i == n - 1) {
                ans += cnt / 2;
            }
        } else {
            ans += cnt / 2;
            cnt = 1;
        }
    }
    cout << ans << endl;

    return 0;
}