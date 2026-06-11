#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    complex<int> c1(x1, y1), c2(x2, y2), rot(0, -1), c3 = rot * (c1 - c2) + c2, c4 = rot * (c2 - c3) + c3;
    cout << c3.real() << " " << c3.imag() << " " << c4.real() << " " << c4.imag() << endl;
    return 0;
}