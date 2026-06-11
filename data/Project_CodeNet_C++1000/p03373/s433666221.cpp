#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int min = A * X + B * Y;
    if (A + B > 2 * C) {
        if (X == Y) min = C * X * 2;
        else if (X > Y) {
            if (A >= C * 2) min = C * X * 2;
            else min = A * (X - Y) + C * Y * 2;
        } else {
            if (B >= C * 2) min = C * Y * 2;
            else min = B * (Y - X) + C * X * 2;
        }
    } 
    cout << min << endl;
}
