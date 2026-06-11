#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    int n, m, X, Y, x, y;
    cin >> n >> m >> X >> Y;
    int minx = X, maxx = X, miny = Y, maxy = Y;
    for (int i = 0; i < n; i++) {
        cin >> x;
        minx = min(minx, x);
        maxx = max(maxx, x);
    }
    for (int i = 0; i < m; i++) {
        cin >> y;
        miny = min(miny, y);
        maxy = max(maxy, y);
    }
    if (maxx < miny || maxy < minx) {
        cout << "No War" << endl;
    }
    else cout << "War" << endl;
}