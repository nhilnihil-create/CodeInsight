#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int c0 = 0, c1 = 0;
    rep(i, n) {
        if (s[i] == '0') c0++;
        if (s[i] == '1') c1++;
    }
    cout << 2 * min(c0, c1) << endl;
}