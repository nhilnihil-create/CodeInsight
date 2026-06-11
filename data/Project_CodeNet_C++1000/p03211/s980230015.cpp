#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int to_int(char ch) {
    return (int)(ch - '0');
}

int main() {
    fastIO;

    string s;
    cin >> s;

    int min_diff = 999;
    for (size_t i = 0; i < s.size() - 2; i++) {
        int subsum = to_int(s.at(i)) * 100 + to_int(s.at(i + 1)) * 10 +
                     to_int(s.at(i + 2));
        min_diff = min(min_diff, abs(753 - subsum));
    }
    cout << min_diff << endl;
}
