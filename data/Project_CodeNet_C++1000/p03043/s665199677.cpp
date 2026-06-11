#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)

int main() {
    double n, k;
    cin >> n >> k;
    long double ans = 0.0;
    for(double i = 1.0; i <= n; i++) i < k ? ans += (1 / n) * pow(0.5, ceil(log2(k / i))) : ans += 1 / n;
    cout << fixed << setprecision(10) << ans << endl;
}
