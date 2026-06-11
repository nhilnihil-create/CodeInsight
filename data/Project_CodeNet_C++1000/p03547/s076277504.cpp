#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char x, y;
    cin >> x >> y;
    int xtwo = x;
    int ytwo = y;
    if (xtwo < ytwo) {
        cout << '<';
        return 0;
    }
    if (xtwo == ytwo) {
        cout << '=';
        return 0;
    } else {
        cout << '>';
        return 0;
    }
}