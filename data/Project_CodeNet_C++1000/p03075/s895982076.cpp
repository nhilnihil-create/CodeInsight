#include <bits/stdc++.h>

using namespace std;

int main() {
    int a = 0, b = 0, c = 0, d = 0, e = 0, k = 0;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> e;
    cin >> k;
    if (a < b && b < c && c < d && d < e) {
        if (k < e - a || k < e - b || k < e - c || k < e - d) {
            cout << ":(" << endl;
        } else {
            cout << "Yay!" << endl;
        }
    } else {
        cout << ":(" << endl;
    }

}