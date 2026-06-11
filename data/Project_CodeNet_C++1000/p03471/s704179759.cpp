#include <iostream>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;

int main(void) {
    Int n, y;
    cin >> n >> y;
    for (Int i = 0; i <= min(y / 10000, n); ++i) {
        for (Int j = 0; j <= min(y / 5000, n - i); ++j) {
            if (i * 10000 + j * 5000 + (n - i - j) * 1000 == y) {
                cout << i << " " << j << " " << n - i - j << endl;
                return 0;
            }
        }
    }
    cout << "-1 -1 -1" << endl;
    return 0;
}

