#include <bits/stdc++.h>
using namespace std;

int main(void) {
    long long a, b, c, k;
    cin >> a >> b >> c >> k;
    if (abs(a - b) > 1e18) {
        cout << "Unfair" << endl;
        return 0;
    }
    if (k % 2 == 0) {
        cout << a - b << endl;
    }
    else {
        cout << b - a << endl;
    }
    return 0;
}