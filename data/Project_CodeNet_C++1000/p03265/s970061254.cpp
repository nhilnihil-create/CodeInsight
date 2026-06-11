// https://atcoder.jp/contests/abc108/tasks/abc108_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int dy = y2 - y1;
    int dx = x2 - x1;

    int x3, y3, x4, y4;
    x3 = x2 - dy;
    y3 = y2 + dx;
    x4 = x3 - dx;
    y4 = y3 - dy;

    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
    return 0;
}

// 4 3
// 1 2
