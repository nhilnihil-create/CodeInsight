#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    if (x % y == 0) {
        cout << -1 << endl;
    }
    else {
        int i = 1;
        while(1) {
            if (i % x == 0 && i % y != 0) {
                cout << i << endl;
                break;
            }
            i *= x;
        }
    }
}
