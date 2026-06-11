#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    string s, t;
    cin >> s >> t;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<char>());

    int length = min(s.size(), t.size());

    bool can = true;
    int countOfEqual = 0;
    rep(i, length) {
        if (s.at(i) < t.at(i)) {
            break;
        } else if(t.at(i) < s.at(i)){
            can = false;
            break;
        } else if (s.at(i) == t.at(i)) {
            countOfEqual++;
        }
    }

    if (countOfEqual == length) {
        if (t.size() <= s.size()) {
            can = false;
        }
    }

    string ans = can ? "Yes" : "No";

    cout << ans << endl;

    return 0;
}
