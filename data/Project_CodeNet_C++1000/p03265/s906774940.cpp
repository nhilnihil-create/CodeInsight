#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int x_1, y_1, x_2, y_2;
    cin >> x_1 >> y_1 >> x_2 >> y_2;
    int dx = x_2 - x_1;
    int dy = y_2 - y_1;
    int x = x_2, y = y_2;
    rep(i, 2){
        int _dx = -dy;
        int _dy = dx;
        dx = _dx;
        dy = _dy;
        x += dx;
        y += dy;
        cout << x << " " << y;
        if (i == 0) cout << " ";
        else cout << endl;
    }

}
