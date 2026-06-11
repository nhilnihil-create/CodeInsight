#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

string makeTurnString(string S) {
    string L;
    L.push_back(S.at(S.size() - 1));
    for (int i = 0; i < S.size() - 1; i++) {
        L.push_back(S.at(i));
    }
    return L;
}

int main() {
    string S, T;
    cin >> S >> T;

    string ans = "No";
    rep(i, S.size()) {
        if (S == T) ans = "Yes";
        S = makeTurnString(S);
    }

    cout << ans << endl;

    return 0;
}
