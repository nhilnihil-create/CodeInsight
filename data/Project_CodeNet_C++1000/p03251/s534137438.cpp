#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

bool check_x(int *x, int N, int Z) {
    bool ok = true;
    rep(0, N) {
        if (Z <= x[i]) {
            ok = false;
            break;
        }
    }

    return ok;
}

bool check_y(int *y, int M, int Z) {
    bool ok = true;
    rep(0, M) {
        if (y[i] < Z) {
            ok = false;
            break;
        }
    }

    return ok;
}

void solve() {
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;

    int x[N];
    rep(0, N) cin >> x[i];
    
    int y[M];
    rep(0, M) cin >> y[i];

    bool found = false;
    rep(0, 101) {
        if (X < i && i <= Y && check_x(x, N, i) && check_y(y, M, i)) {
            found = true;
            break;
        }
    }
    cout << (found ? "No War" : "War") << endl;
}

int main() {
    solve();

    return 0;
}
