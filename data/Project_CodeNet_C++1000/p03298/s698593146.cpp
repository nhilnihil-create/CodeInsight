#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<pair<string, string>, int> k[2];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    string s[2] = { "", "" };
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        s[0] += c;
    }
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        s[1] = c + s[1];
    }
    for (int q = 0; q < 2; ++q) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            string t1 = "", t2 = "";
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    t1 += s[q][i];
                } else {
                    t2 += s[q][i];
                }
            }
            ++k[q][make_pair(t1, t2)];
        }
    }
    ll ans = 0;
    for (auto p : k[0]) {
        if (k[1].count(p.first)) {
            ans += ll(p.second) * k[1][p.first];
        }
    }
    cout << ans;
    return 0;
}
