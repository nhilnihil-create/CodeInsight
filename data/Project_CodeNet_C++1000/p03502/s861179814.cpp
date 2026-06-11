#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    int x;
    cin >> x;

    int y = x;
    int z = y % 10;
    while (y != 0) {
        y = y / 10;
        z += y % 10;
    }

    if (x % z == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}