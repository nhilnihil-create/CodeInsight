// https://atcoder.jp/contests/apc001/tasks/apc001_c
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int n;
    string s, t = "";
    cin >> n;
    int l = 0, r = n;
    cout << 0 << endl;
    cin >> s;
    if (s == "Vacant")
        return 0;
    while (t != "Vacant") {
        int m = (l + r) / 2;
        cout << m << endl;
        cin >> t;
        if (m % 2 ^ s == t)
            l = m;
        else
            r = m;
    }

    return 0;
}
