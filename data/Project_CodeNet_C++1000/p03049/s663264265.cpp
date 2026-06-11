#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int ans = 0;
    int acnt = 0, bcnt = 0, abcnt = 0;
    for (int i = 0; i < n; i++) {
        int m = s[i].length();
        for (int j = 0; j < m - 1; j++) {
            if (s[i][j] == 'A' && s[i][j+1] == 'B') ans++;
        }
        if (s[i][0] == 'B' && s[i][m-1] == 'A') abcnt++;
        else if (s[i][0] == 'B') bcnt++;
        else if (s[i][m-1] == 'A') acnt++;
    }

    if (acnt == 0 && bcnt == 0) ans += max(0, abcnt - 1);
    else ans += abcnt + min(acnt, bcnt);

    cout << ans << endl;
    return 0;
}
