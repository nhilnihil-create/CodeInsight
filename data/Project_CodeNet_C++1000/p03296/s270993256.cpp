#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using ll = int64_t;
using ul = uint64_t;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> slimes(n);
    for (auto &s : slimes) cin >> s;

    int prev = slimes.front();
    int cnt = 0, subcnt = 1;
    for (size_t i = 1; i < slimes.size(); i++) {
        if (slimes.at(i) == prev) {
            subcnt++;
        } else {
            cnt += subcnt / 2;
            subcnt = 1;
        }
        prev = slimes.at(i);
    }
    if (subcnt != 1) {
        cnt += subcnt / 2;
    }
    cout << cnt << endl;
}

int main() {
    fastIO;
    // rep(i, 4) {
    //     cout << ">>>>>>>>>> NO. " << (i + 1) << endl;
    //     solve();
    //     cout << endl;
    // }
    solve();
}
