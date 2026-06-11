#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        auto t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int t;
    cin >> t;
    for (long long a, b, c, d; cin >> a >> b >> c >> d; ) {
        if (a < b || d < b) {
            cout << "No\n";
        } else {
            long long g = gcd(b, d);
            auto k = c / g * g + a % g;
            if (k <= c) {
                k += g;
            }
            if (k >= b) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
    return 0;
}