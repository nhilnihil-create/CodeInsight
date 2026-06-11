#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int xd = c - a;
    int yd = d - b;
    int x_3 = c - yd;
    int y_3 = d + xd;
    int x_4 = x_3 - xd;
    int y_4 = y_3 - yd;
    cout << x_3 << ' ' << y_3 << ' ' << x_4 << ' ' << y_4 << '\n';
}
