#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastIO;
    string s;
    cin >> s;
    // 0123456789
    // 2019/04/30
    if (s[6] >= '5' || s[5] == '1') {
        cout << "TBD";
    } else {
        cout << "Heisei";
    }
}