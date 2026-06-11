#include <bits/stdc++.h>

using namespace std;

int n, m, p, r, c;
string s, t;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> p >> r >> c >> s >> t;

    int cur = r;
    for (int i = 0; i < p; i++) {
        if (s[i] == 'U') cur--;
        if (cur < 1) return cout << "NO", 0;
        if (t[i] == 'D' && cur < n) cur++;
    }

    cur = r;
    for (int i = 0; i < p; i++) {
        if (s[i] == 'D') cur++;
        if (cur > n) return cout << "NO", 0;
        if (t[i] == 'U' && cur > 1) cur--;
    }

    cur = c;
    for (int i = 0; i < p; i++) {
        if (s[i] == 'L') cur--;
        if (cur < 1) return cout << "NO", 0;
        if (t[i] == 'R' && cur < m) cur++;
    }

    cur = c;
    for (int i = 0; i < p; i++) {
        if (s[i] == 'R') cur++;
        if (cur > m) return cout << "NO", 0;
        if (t[i] == 'L' && cur > 1) cur--;
    }

    cout << "YES";
    return 0;
}
