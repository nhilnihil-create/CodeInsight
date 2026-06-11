#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    string s;
    cin >> s;

    int ans = 0;
    rep(i, s.size()) {
        if (s[i] == '+')
            ans++;
        else
            ans--;
    }
    cout << ans << endl;

    return 0;
}
