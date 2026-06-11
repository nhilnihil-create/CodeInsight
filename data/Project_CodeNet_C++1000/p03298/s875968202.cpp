#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    map<string, int> mp;

    ll ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        string frw = "", bkw = "";
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) != 0)
                frw.push_back(s[i]);
            else
                bkw.push_back(s[i]);
        }

        reverse(bkw.begin(), bkw.end());
        mp[frw + "@" + bkw]++;
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        string frw = "", bkw = "";
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) != 0)
                frw.push_back(s[i + n]);
            else
                bkw.push_back(s[i + n]);
        }

        reverse(frw.begin(), frw.end());
        string str = frw + "@" + bkw;
        reverse(str.begin(), str.end());

        ans += mp[str];
    }

    cout << ans;
}

int main() {
    solve();
    return 0;
}