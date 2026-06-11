#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;
// ------------------------------

int main() {
    string S;
    cin >> S;
    int cnt = 0;
    rep(i, S.size()) if (S[i] == 'B') cnt += 1;
    ll ans = 0;
    int last = S.size() - 1;
    for (int i = S.size() - 1; cnt != 0; --i) {
        if (S[i] == 'B') {
            ans += last - i;
            cnt -= 1;
            last -= 1;
        }
    }
    cout << ans << endl;
    return 0;
}
