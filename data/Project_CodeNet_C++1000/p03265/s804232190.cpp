#include <bits/stdc++.h>
using namespace std;

int main() {
    int x_1, x_2, y_1, y_2, a, b;
    cin >> x_1 >> y_1 >> x_2 >> y_2;
    a = x_2 - x_1;
    b = y_2 - y_1;
    cout << x_2 - b << " " << y_2 + a << " " << x_1 - b << " " << y_1 + a << " " << endl;

    return 0;
}
