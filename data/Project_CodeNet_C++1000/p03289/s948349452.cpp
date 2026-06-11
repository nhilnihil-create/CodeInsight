#include <bits/stdc++.h>
using namespace std;

int sumDigits(int num) { return num / 10000 + num % 10000 / 1000 + num % 1000 / 100 + num % 100 / 10 + num % 10; }
int main() {
    string S;
    cin >> S;
    int cCnt = 0;
    for (int i = 0; i < S.length(); i++) {
        if (i == 0) {
            if (S[i] != 'A') {
                cout << "WA" << endl;
                return 0;
            }
        }
        if (i >= 2 && i <= S.length() - 2) {
            if (S[i] == 'C') {
                cCnt++;
            }
        }
        if (S[i] != 'A' && S[i] != 'C') {
            if (isupper(S[i])) {
                cout << "WA" << endl;
                return 0;
            }
        }
    }
    if (cCnt != 1) {
        cout << "WA" << endl;
        return 0;
    }
    cout << "AC" << endl;

    return 0;
}