#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int L = a+b, R = c+d;
    if (L > R) {
        cout << "Left" << endl;
    } else if (L < R) {
        cout << "Right" << endl;
    } else {
        cout << "Balanced" << endl;
    }
}