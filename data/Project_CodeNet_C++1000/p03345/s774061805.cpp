#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, c, k;
    cin >> a >> b >> c >> k;

    bool even = (k % 2 == 0);
    if (abs(a-b) > 1000000000000000000) {
        cout << "Unfair" << endl;
    } else {
        if (even) {
            cout << a - b << endl;
        } else {
            cout << b - a << endl;
        }
    }

    return 0;
}
