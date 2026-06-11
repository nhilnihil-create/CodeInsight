#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int d1 = x2 - x1;
    int d2 = y2 - y1;

    cout << x2 - d2 <<  " " << y2 + d1 << " " <<  x1 -d2 << " " << y1 + d1 << endl;
}
