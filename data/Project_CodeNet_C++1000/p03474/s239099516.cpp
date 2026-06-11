#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B; cin >> A >> B;
    string s; cin >> s;
    for (int i = 0; i < A; i++) {
        if (!isdigit(s[i])) {
            cout << "No" << endl;
            return 0;
        }
    }
    if (s[A] != '-') {
        cout << "No" << endl;
        return 0;
    }
    for (int i = A + 1; i <= A + B; i++) {
        if (!isdigit(s[i])) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}