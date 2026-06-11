#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    string s; cin >> s;
    int n = s.length();

    ll ans = 0;
    ll cnt = 0;
    for (int i = 0; i < n - 2; ++i) {
        if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
            s[i + 2] = 'A';

            ans += cnt + 1;
            i++;
        } else if (s[i] == 'A') {
            cnt++;
        } else {
            cnt = 0;
        }
    }

    cout << ans << endl;
}