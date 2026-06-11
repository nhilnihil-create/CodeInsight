#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main() {
    double ans = 0;
    ll n;
    cin >> n;
    rep(i, 0, n) {
        double x;
        string u;
        cin >> x >> u;
        if(u == "JPY") ans += x;
        else ans += 380000.0 * x;
    }
    printf("%.10lf\n", ans);
    return 0;
}