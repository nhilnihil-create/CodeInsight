#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {

    int A, B, X;

    cin >> A >> B >> X;

    if (A == X) {
        cout << "YES" << endl;
    }

    else if (A < X && (A + B) >= X) {
        cout << "YES" << endl;
    }

    else {
        cout << "NO" << endl;
    }
    
}