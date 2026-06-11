#include <iostream>
#include <algorithm>

using namespace std;

bool solve(long long a, long long b, long long c, long long d) {
    if (a < b || d < b)return false;
    if (b - 1 < c + 1)return true;

    long long x = __gcd(b, d);
    a %= b;
    return a + (b - a - 1) / x * x <= c;
}

int main() {
    int t;
    cin >> t;
    for (; t > 0; t--) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << (solve(a, b, c, d) ? "Yes" : "No") << endl;
    }
    return 0;
}