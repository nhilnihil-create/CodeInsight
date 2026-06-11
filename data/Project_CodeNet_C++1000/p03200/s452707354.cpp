#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    long long ans = 0, w = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'W') {
            ans += i - w;
            w++;
        }
    }
    cout << ans << endl;
}