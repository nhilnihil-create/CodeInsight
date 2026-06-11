#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;
    int cnt = 0;
    if (S.at(0) != 'A') {
        cout << "WA" << endl;
        return 0;
    }
    for (int i = 1; i < S.size(); i++) {
        if (S.at(i) > 96) continue;
        else if (i >= 2 && i <= S.size() - 2) {
            if (S.at(i) == 'C') cnt++;
        } else {
            cout << "WA" << endl;
            return 0;
        }
    }
    if (cnt == 1) {
        cout << "AC" << endl;
    } else cout << "WA" << endl;
}