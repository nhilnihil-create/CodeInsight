#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    string S;
    cin >> S;
    bool chk1 = false, chk2 = true;

    if (S[A] == '-') {
        chk1 = true;
    }
    for (int i = 0; i < A + B + 1; i++) {
        if (S[i] == '-' && i != A) chk2 = false;
    }

    if (chk1 && chk2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}