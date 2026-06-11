#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, Yen = 0;
    long double b, Btc = 0;
    string s;

    cin >> n;

    rep(i,n) {
        cin >> b >> s;
        if (s == "JPY") {
            Yen += b;
        } else {
            Btc += b;
        }
    }

    long double BC = 380000.0 * Btc;
    long double ans = Yen + BC;

    cout << ans << endl;

    return 0;
}