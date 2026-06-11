#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int l = 0, r = s.size() - 1;
    int ans = 0;
    while (l < r) {
        if (s[l] == s[r]) {
            l++;
            r--;
        } else if (s[l] == 'x') {
            ans++;
            l++;
        } else if (s[r] == 'x') {
            ans++;
            r--;
        } else {
            ans = -1;
            break;
        }
    }
    cout << ans << endl;
}