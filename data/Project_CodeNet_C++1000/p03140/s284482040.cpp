#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int cnts[111][30];

int main() {
    int n;
    string a, b, c;
    cin >> n >> a >> b >> c;
    for (int i = 0; i < n; i++) {
        cnts[i][a[i] - 'a']++;
        cnts[i][b[i] - 'a']++;
        cnts[i][c[i] - 'a']++;
    }
    string s;
    for (int i = 0; i < n; i++) {
        int maxv = 0, idx = 0;
        for (int j = 0; j < 30; j++) {
            if (maxv < cnts[i][j]) {
                maxv = cnts[i][j];
                idx = j;
            }
        }
        s += (idx + 'a');
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != s[i]) ans++;
        if (b[i] != s[i]) ans++;
        if (c[i] != s[i]) ans++;
    }
    cout << ans << endl;
}