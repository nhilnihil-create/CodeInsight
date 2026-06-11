#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    int n, m, x;
    cin >> n >> m >> x;
    vector<bool> A(n + 1);
    rep(i, m) {
        int pos;
        cin >> pos;
        A.at(pos) = true;
    }

    int lcost = 0, rcost = 0;
    for (size_t i = 0; i < A.size(); i++) {
        if (i < x && A.at(i))
            lcost++;
        if (x < i && A.at(i))
            rcost++;
    }
    cout << min(lcost, rcost) << endl;
}
