#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int max = 100;
    string s[max];
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (s[i] == "Y") {
            cout << "Four" << endl;
            return 0;
        }
    }
    cout << "Three" << endl;
    return 0;
}