#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using ll = long long;
#define INF 1e9

int main() {
    string s; cin >> s;

    ll ans = 0; ll cur = 0;
    REP(i, s.size()) {
        if (s[i] == 'W') {
            ans += i - cur;
            ++cur;
        }
    }

    cout << ans << endl;

    return 0;
}