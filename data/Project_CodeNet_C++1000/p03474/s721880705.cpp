#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    if (s.at(a) != '-') {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0; i < a + b + 1; i++) {
        if (i == a) continue;
        if (!isdigit(s.at(i))) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}