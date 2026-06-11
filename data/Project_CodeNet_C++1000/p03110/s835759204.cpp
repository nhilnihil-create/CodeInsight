#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    double ans = 0;
    rep(i, N) {
        double x;
        string u;
        cin >> x >> u;
        if (u == "JPY") ans += x;
        else ans += 380000.0*x;
    }
    printf("%.5lf", ans);
    return 0;
}