#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
array<int, N> a, front_gcd, back_gcd;

int main() {
    cin >> n;
    for (int i = 1, cum_gcd; i <= n; i++) {
        cin >> a[i];
        if (i == 1) {
            cum_gcd = a[i];
        } else {
            cum_gcd = __gcd(cum_gcd, a[i]);
        }
        front_gcd[i] = cum_gcd;
    }
    
    for (int i = n, cum_gcd = a[n]; i >= 1; i--) {
        cum_gcd = __gcd(cum_gcd, a[i]);
        back_gcd[i] = cum_gcd;
    }
    front_gcd[0] = back_gcd[2];
    back_gcd[n + 1] = front_gcd[n - 1];

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, __gcd(front_gcd[i - 1], back_gcd[i + 1]));
    }

    cout << ans << endl;
}

