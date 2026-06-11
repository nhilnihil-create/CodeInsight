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
    for (int bit = 0; bit < (1 << 3); ++bit) {
        int tmp = (int)(S[0] - '0');
        string ans = "";
        ans += S[0];
        rep(i, 3) {
            if (bit & (1 << i)) {
                tmp += (int)(S[i + 1] - '0');
                ans += "+";
            }
            else {
                tmp -= (int)(S[i + 1] - '0');
                ans += "-";
            }
            ans += S[i + 1];
        }
        if (tmp == 7) {
            cout << ans + "=7" << endl;
            return 0;
        }
    }
    return 0;
}