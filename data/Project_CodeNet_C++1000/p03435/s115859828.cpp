#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

constexpr ll INF = ll(1e+18) + 1;

ll dist(ll a, ll b, ll c, ll d) {
    return abs(a-c) + abs(b-d);
}

int main() {
    int c[3][3];
    int buf;

    rep(i, 3) {
        rep(j, 3) {
            cin >> buf;
            c[i][j] = buf;
        }
    }

    rep (i, 3) {
        rep (j, 3) {
            if (c[i%3][j%3]+c[(i+1)%3][(j+1)%3] != c[(i+1)%3][j%3]+c[i%3][(j+1)%3]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
}
