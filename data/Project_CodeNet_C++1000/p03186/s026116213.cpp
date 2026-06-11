#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b >= c) {
        cout << b + c;
    } else {
        cout << 2 * b + a + 1;
    }
    return 0;
}