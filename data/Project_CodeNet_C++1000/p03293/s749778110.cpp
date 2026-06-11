#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long int;
using namespace std;
int main() {
    fastIO;
    string s, t;
    cin >> s >> t;
    s += s;
    for (size_t i = 0; i < s.size() / 2; i++) {
        if (s.substr(i, s.size() / 2) == t) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}