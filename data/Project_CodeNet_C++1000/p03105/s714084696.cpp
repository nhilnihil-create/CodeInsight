#include <bits/stdc++.h>

using namespace std;

int main() {
    int A = 0, B = 0, C = 0;
    cin >> A >> B >> C;

    if (C * A <= B) {
        cout << C << endl;
    } else {
        cout << B / A << endl;
    }
}