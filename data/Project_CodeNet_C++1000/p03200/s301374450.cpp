#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = (int)s.size();
    ll ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            cnt++;
        } else {
            ans += cnt;
        }
    }
    cout << ans << '\n';
    return 0;
}