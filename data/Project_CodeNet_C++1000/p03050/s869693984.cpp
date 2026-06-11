#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, ans = 0;
    cin >> n;

    for (long long i = 1; i * i <= n; i++) {
        long long x = n / i;
        long long shift = i - n % x;
        if (shift % i == 0)
            x -= shift / i;
        if (x)
            ans += x * (n / x == i && n % x == i);
    }
    cout << ans << '\n';
}
