#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string s;
    cin >> s;
    int prev = s.at(0) - '0';
    int ans = 0;
    for (int i = 1; i < (int)s.size(); i++) {
        int n = s.at(i) - '0';
        if (n == prev) {
            n = 1 - prev;
            s.at(i) = (char)n;
            ans++;
        }
        prev = n;
    }
    cout << ans << endl;
    return 0;
}
