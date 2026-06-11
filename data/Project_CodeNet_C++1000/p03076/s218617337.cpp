#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define ll long long

int main() {
    //入力
    vector<int> a(5);
    rep(i, 5) cin >> a[i];
    //
    int maxmod = 0;
    int maxi = 0;
    rep(i, 5) {
        if (a[i] % 10 != 0) {
            int m = 10 - a[i] % 10;
            if (m > maxmod) {
                maxmod = m;
                maxi = i;
            }
        }
    }
    int ans = 0;
    rep(i, 5) {
        if (i != maxi) {
            int m = a[i] % 10;
            if (m != 0) {
                ans += (a[i] / 10)*10 + 10;
            }
            else {
                ans += a[i];
            }
        }
    }
    ans += a[maxi];

    cout << ans << endl;
    return 0;
}