#include <bits/stdc++.h>
using namespace std;

int main() {
    long long T, a, b, c, d;
    cin >> T;
    while (T--) {
        cin >> a >> b >> c >> d;
        if (b > a || b > d) { printf("No\n"); continue; }
        long long g = __gcd(b, d);
        printf("%s\n", (a - (a - c - 1) / g * g - b) >= 0 ? "Yes" : "No");
    }
    return 0;
}