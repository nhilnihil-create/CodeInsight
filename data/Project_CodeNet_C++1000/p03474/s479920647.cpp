#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int A, B;
    cin >> A >> B;
    string S;
    cin >> S;
    bool iscan = true;
    for (int i=0; i<A; i++) {
        if (S[i] < '0' || S[i] > '9') {
            iscan = false;
        }
    }

    if (S[A] != '-') {
        iscan = false;
    }

    for (int i=A+1; i<=A+B; i++) {
        if (S[i] < '0' || S[i] > '9') {
            iscan = false;
        }
    }

    if (iscan) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}