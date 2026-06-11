#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastIO;
    vector<int> vi(3);
    rep(i, 3) cin >> vi.at(i);
    sort(vi.begin(), vi.end());

    int cost = 0;
    for (int i = 1; i <= 2; i++) {
        cost += abs(vi.at(i) - vi.at(i - 1));
    }
    cout << cost << endl;
}
