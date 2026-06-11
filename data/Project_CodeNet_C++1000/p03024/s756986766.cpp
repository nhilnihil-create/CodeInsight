#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int n = 15 - s.size();
    int cnt = 0;
    for (char c: s) {
        if (c == 'o') cnt++;
    }
    bool ans = (cnt + n >= 8);
    cout << (ans ? "YES" : "NO") << endl;
}