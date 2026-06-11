#include <iostream>

using namespace std;

int main() {
    const long long ub = 3500;
    long long n; cin >> n;
    for (long long x = 1; x <= ub; ++x) {
        for (long long y = 1; y <= ub; ++y) {
            long long p = n*x*y;
            long long q = 4*x*y - n*y - n*x;
            if ((q > 0) && (p % q == 0)) {
                long long z = p / q;
                cout << x << " " << y << " " << z << endl;
                return 0;
            }
        }
    }
    return -1;
}