#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int flag = 0;
    string s;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "Y") {
            flag = 1;
            break;
        }
    }
    if (flag) {
        cout << "Four" << endl;
    }
    else {
        cout << "Three" << endl;
    }
}
