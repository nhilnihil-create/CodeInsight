#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using namespace std;

int main() {
    fastIO;
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<int> X(n);
    vector<int> Y(m);

    rep(i, n) cin >> X.at(i);
    rep(i, m) cin >> Y.at(i);

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    int x_max = X.back();
    int y_min = Y.front();

    vector<int> possible;
    for (int i = x_max + 1; i <= y_min; i++) {
        possible.push_back(i);
    }

    for (auto p : possible) {
        if (x < p && p <= y) {
            cout << "No War";
            return 0;
        }
    }

    cout << "War";
    return 0;
}