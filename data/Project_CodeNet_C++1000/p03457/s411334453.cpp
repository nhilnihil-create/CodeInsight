#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    array<int, 3> a = {0, 0, 0}, b;
    int t, x, y;
    for (int i = 0; i < n; i++) {
        cin >> b[0] >> b[1] >> b[2];
        t = b[0] - a[0];
        x = abs (b[1] - a[1]);
        y = abs (b[2] - a[2]);
        if (x+y > t || x+y < t && (x+y-t)&1) {
            cout << "No" << endl;
            return 0;
        }
        a = b;
    }
    cout << "Yes" << endl;
}