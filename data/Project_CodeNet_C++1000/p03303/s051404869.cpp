#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int w;
    cin >> s >> w;

    string ans;
    for (int i = 0; i < s.length(); i++) {
        if (i % w == 0) ans += s[i];
    }
    cout << ans << endl;
}