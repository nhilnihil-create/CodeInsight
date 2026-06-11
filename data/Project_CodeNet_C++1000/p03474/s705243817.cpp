#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B;
    string S; cin >> A >> B >> S;
    for (int i = 0; i < A+B+1; i++) {
        if (i != A) {
            if (S.at(i) == '-') {
                cout << "No" << endl;
                return 0;
            }
        } else {
            if (S.at(i) != '-') {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    if (S.size() == A+B+1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}