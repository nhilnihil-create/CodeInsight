#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

void solve() {
    int n;
    cin >> n;

    double x, sum = 0.0;
    string u;
    rep(0, n) {
        cin >> x >> u;
        if (u == "JPY") {
            sum += x;
        } else if (u == "BTC") {
            sum += (x * 380000.0);
        }
    }
    printf("%lf\n", sum);
}

int main() {
    solve();

    return 0;
}
