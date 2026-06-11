#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int A, B;
    cin >> A >> B;
    string S;
    cin >> S;

    bool isOk = true;
    rep(i, S.size()) {
        if (i == A) {
            if (S.at(i) != '-')
                isOk = false;
        } else {
            if (S.at(i) < '0' || '9' < S.at(i))
                isOk = false;
        }
    }

    string ans = isOk ? "Yes" : "No";

    cout << ans << endl;

    return 0;
}
