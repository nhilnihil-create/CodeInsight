#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    string S;
    cin >> S;

    vector<int> ignoreOffset;
    string ans = "AC";

    // 1
    if (S.at(0) != 'A') ans = "WA";
    if (S.at(0) == 'A') ignoreOffset.push_back(0);

    // 2
    int count = 0;
    int offset = 0;
    rep(i, S.size()) {
        if (2 <= i && i <= S.size() - 2) {
            if (S.at(i) == 'C') {
                count++;
                offset = i;
            }
        }
    }
    if (count != 1) ans = "WA";
    if (count == 1) {
        ignoreOffset.push_back(offset);
    }

    // 3
    if (ans == "AC") {
        rep(i, S.size()) {
            if (S.at(i) < 'a' || 'z' < S.at(i)) {
                bool isOk = false;
                for (int offset : ignoreOffset) {
                    if (i == offset) isOk = true;
                }
                if (!isOk) ans = "WA";
            }
        }
    }

    cout << ans << endl;

    return 0;
}
