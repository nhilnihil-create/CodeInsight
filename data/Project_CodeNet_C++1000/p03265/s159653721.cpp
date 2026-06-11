#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int x_1, y_1, x_2, y_2;
    cin >> x_1 >> y_1 >> x_2 >> y_2;
    int dx = x_2 - x_1;
    int dy = y_2 - y_1;
    int x_3 = x_2 + (-dy);
    int y_3 = y_2 + dx;
    int x_4 = x_3 + (-dx);
    int y_4 = y_3 + (-dy);
    cout << x_3 << " " << y_3 << " " << x_4 << " " << y_4 << endl;
}
