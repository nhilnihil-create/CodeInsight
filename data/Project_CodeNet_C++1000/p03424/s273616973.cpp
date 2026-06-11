#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;

    bool ex = false;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "Y") ex = true;
    }

    if (!ex) {
        cout << "Three" << endl;
    } else {
        cout << "Four" << endl;
    }

    return 0;
}
