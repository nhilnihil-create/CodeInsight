#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    pair<int, int> d[n];

    if (s[0] == 'E')
        d[0].first = 1;
    else
        d[0].second = 1;

    rep(i, n - 1) {
        d[i + 1].first += d[i].first;
        d[i + 1].second += d[i].second;

        if (s[i + 1] == 'E')
            d[i + 1].first += 1;
        else
            d[i + 1].second += 1;
    }

    int w = count(s.cbegin(), s.cend(), 'W');
    int e = count(s.cbegin(), s.cend(), 'E');

    int ans = 1e6;
    for (int i = 0; i < n; i++) {
        int lw = (s[i] == 'W') ? d[i].second - 1 : d[i].second;
        int re = e - d[i].first;
        ans = min(ans, lw + re);
    }

    cout << ans << endl;
    return 0;
}
