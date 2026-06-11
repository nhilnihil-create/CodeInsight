#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    if (s[0] == '0' || s[n - 1] == '1') {
        cout << -1 << endl; exit(0);
    }
    for (int i = 1; i < n - 1; i++) {
        if (s[i - 1] ^ s[n - i - 1]) { cout << -1 << endl; exit(0); }
    }
    for (int i = 2, cur = 1; i <= n; i++) {
        cout << cur << " " << i << endl;
        if (s[i - 2] == '1') cur = i;
    }
    return 0;
}