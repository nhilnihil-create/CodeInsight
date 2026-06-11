#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int ans = 0;
    for (int i = a; i <= b; i++) {
        string s = to_string(i);
        string s2 = s;
        reverse (s2.begin(), s2.end());
        if (s == s2) ans++;
    }
    cout << ans << endl;
}