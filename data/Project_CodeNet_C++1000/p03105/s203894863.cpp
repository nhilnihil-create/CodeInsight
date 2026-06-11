#include <bits/stdc++.h>
using namespace std;

int main() {

    int A, B, C;

    cin >> A >> B >> C;

    if (B/A >= C) {
        cout << C << endl;
    }
    else if (B/A < C) {
        cout << B/A << endl;
    }
    else {
        cout << 0 << endl;
    }
}