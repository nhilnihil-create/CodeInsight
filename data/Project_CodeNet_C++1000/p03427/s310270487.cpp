#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    string s; cin >> s;
    int n = s.length();

    if (n == 1) {
        cout << s << endl;
    } else {
        bool q = true;
        for (int i = 1; i < n; ++i) {
            if (s[i] != '9') {
                q = false;
            }
        }

        if (q) {
            cout << s[0] - '0' + 9 * (n - 1) << endl;
            return 0;
        }

        if (s[0] == '1') {
            cout << 9 * (n - 1) << endl;
        } else {
            cout << s[0] - '0' - 1 + 9 * (n - 1) << endl;
        }
    }
}