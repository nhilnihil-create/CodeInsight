#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> a(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> a[i][j];
    
    vector<int> y, x, Y, X;
    rep(i, H) rep(j, W - 1) {
        if (a[i][j] % 2 == 1) {
            --a[i][j];
            ++a[i][j + 1];
            y.push_back(i);
            x.push_back(j);
            Y.push_back(i);
            X.push_back(j + 1);
        }
    }
    rep(i, H - 1) {
        if (a[i][W - 1] % 2 == 1) {
            --a[i][W - 1];
            ++a[i + 1][W - 1];
            y.push_back(i);
            x.push_back(W - 1);
            Y.push_back(i + 1);
            X.push_back(W - 1);
        }
    }
    
    cout << y.size() << endl;
    rep(i, y.size()) {
        cout << y[i] + 1 << " " << x[i] + 1 << " " << Y[i] + 1 << " " << X[i] + 1 << endl;
    }
    return 0;
}
