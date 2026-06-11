#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    int n, d, x, ans = 0;
    cin >> n >> d >> x;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        for (int j = 1;; j += a) {
            if (j > d)
                break;
            ans++;
        }
    }
    cout << ans + x << endl;
    return 0;
}