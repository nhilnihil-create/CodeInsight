#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;

    int l = 0;
    int r = s.size() - 1;
    int ans = 0;
    while (l < r) {
        if (s[l] == s[r]) {
            l++;
            r--;
        } else if (s[l] == 'x' && s[r] != 'x') {
            l++;
            ans++;
        } else if (s[l] != 'x' && s[r] == 'x') {
            r--;
            ans++;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}