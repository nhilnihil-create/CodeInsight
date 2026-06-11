#include <bits/stdc++.h>
using namespace std;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int xv = x2-x1, yv = y2-y1;
    cout
        << x2 - yv << " "
        << y2 + xv << " "
        << x1 - yv << " "
        << y1 + xv << " " << endl;
}