#include <bits/stdc++.h>
using namespace std;

string s[301];

signed main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> s[i];
    int ans = 0;
    for (int iter = 0; iter < n; ++iter) {
        for (int i = 0; i < n; ++i) 
            rotate(s[i].begin(), s[i].begin() + 1, s[i].end());
        bool fl = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) 
                fl &= (s[i][j] == s[j][i]);
        }
        ans += fl;
    }
    cout << ans * n << "\n";
}
