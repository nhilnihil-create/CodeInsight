#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
using namespace std;
using ll = long long;

int main() {
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    vector<int> x(N);
    vector<int> y(M);
    rep(i, N) cin >> x[i];
    rep(i, M) cin >> y[i];
    sort(x.rbegin(), x.rend());
    sort(y.begin(), y.end());
    FOR(i, x[0] + 1, y[0] + 1) {
        if (X < i && i <= Y) {
            cout << "No War" << endl;
            return 0;
        }
    }
    cout << "War" << endl;
    return 0;
}