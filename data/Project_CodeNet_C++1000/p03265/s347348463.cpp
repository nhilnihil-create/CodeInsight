#include<bits/stdc++.h>

using namespace std;

int main() {

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int x3, y3, x4, y4;

    int x = c - a;
    int y = d - b;

    x3 = c - y;
    y3 = d + x;
    x4 = a - y;
    y4 = b + x;

    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;

    return 0;
}