#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;

    int n;
    cin >> n;
    map<string, int> mp;
    rep(i, n) {
        string input;
        cin >> input;
        if (mp.find(input) != mp.end()) {
            mp[input] += 1;
        } else {
            mp[input] = 1;
        }
    }

    int m;
    cin >> m;
    rep(i, m) {
        string input;
        cin >> input;
        if (mp.find(input) != mp.end()) {
            mp[input] -= 1;
        } else {
            mp[input] = -1;
        }
    }

    int maxv = 0;
    for (const auto el : mp) {
        if (el.second > 0) {
            maxv = max(maxv, el.second);
        }
    }
    cout << maxv << endl;
}