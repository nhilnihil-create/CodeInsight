#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    string s;
    rep(i, 4) {
        string t;
        cin >> t;
        s += t;
    }
    sort(s.begin(), s.end());
    if (s == "1479")
        cout << "YES";
    else
        cout << "NO";
}