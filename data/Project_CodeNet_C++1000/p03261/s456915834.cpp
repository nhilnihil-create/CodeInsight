#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastIO;
    int n;
    cin >> n;
    set<string> used;
    string cur = "(x_x)", prev = ":^)";

    rep(_, n) {
        cin >> cur;

        if (used.find(cur) != used.end()) {
            cout << "No";
            return 0;
        }
        used.insert(cur);

        if (prev != ":^)" && prev.back() != cur.front()) {
            cout << "No";
            return 0;
        }
        prev = cur;
    }

    cout << "Yes";
    return 0;
}