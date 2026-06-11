#include <bits/stdc++.h>
#define fastio (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastio;
    string n;
    cin >> n;

    for (size_t i = 0; i <= 1; i++) {
        if (n[i] == n[i + 1] && n[i + 1] == n[i + 2]) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}