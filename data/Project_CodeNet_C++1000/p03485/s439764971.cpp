#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int x;
    x = (a + b) * 10 / 2;

    if (x % 10 == 0) {
        cout << x / 10 << endl;
    } else {
        cout << x / 10 + 1 << endl;
    }

    return 0;
}
