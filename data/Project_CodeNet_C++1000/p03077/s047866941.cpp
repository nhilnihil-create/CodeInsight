#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)



int main() {
    long n, m = pow(10,15);
    cin >> n;
    rep(i, 5) {
        long c;
        cin >> c; 
        m = min(c, m);
    }
    long ans = 4 + n / m;
    if (n % m != 0) ans++;
    cout << ans << endl;
}