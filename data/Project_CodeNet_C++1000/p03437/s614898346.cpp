#include <bits/stdc++.h>
using namespace std;
#define v(type) vector<type>

int main() {
    int x, y;
    cin >> x >> y;
    const long long a = 1000000000000000000;

    if (x % y == 0) {
        cout << -1 << endl;
        return 0;
    }

    for (long long i = x; i <= a; i += x) {
        if (i % y != 0) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}