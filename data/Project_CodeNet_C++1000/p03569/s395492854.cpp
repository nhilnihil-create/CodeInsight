#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    string s;
    cin >> s;

    int n = s.length();

    int ans = 0;
    int l = 0, r = n - 1;
    while (l <= r) {
        if (s[l] != 'x' && s[r] != 'x' && s[l] != s[r]) {
            cout << -1 << endl;
            return 0;
        }
        if (s[l] == s[r]) {
            l++;
            r--;
        } else if (s[l] == 'x') {
            ans++;
            l++;
        } else {
            ans++;
            r--;
        }
    }

    cout << ans << endl;
    return 0;
}
