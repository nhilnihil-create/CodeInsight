#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int x3, y3, x4, y4;
    int x = x2 - x1;
    int y = y2 - y1;
    x3 = x2 - y;
    y3 = y2 + x;
    x4 = x3 - x;
    y4 = y3 - y;
    cout << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4 << endl;
}