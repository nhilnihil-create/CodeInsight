#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio();
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    switch (n) {
        case 2: cout << s; break;
        default: cout << s[2] << s[1] << s[0]; break;
    }
    //cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s. \n";
    return 0;
}