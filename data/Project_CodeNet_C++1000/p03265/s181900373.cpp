#include <bits/stdc++.h>
using namespace std;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int x = x2, y = y2;
    int vx = x2 - x1;
    int vy = y2 - y1;

    for (int i = 0; i < 2; i++) {
        swap(vx, vy);
        vx *= -1;
        x += vx;
        y += vy;
        cout << x << ' ' << y << endl;
    }
}