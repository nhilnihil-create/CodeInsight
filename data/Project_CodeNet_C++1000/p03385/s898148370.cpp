#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    bool a, b, c;
    a = b = c = false;
    for (int i=0; i < 3; i++) {
        if (S[i] == 'a') {
            a = true;
        } else if (S[i] == 'b') {
            b = true;
        } else if (S[i] == 'c') {
            c = true;
        }
    }

    if (a && b && c) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}