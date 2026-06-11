#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

constexpr ll INF = ll(1e+18) + 1;

ll dist(ll a, ll b, ll c, ll d) {
    return abs(a-c) + abs(b-d);
}

int main() {
    int N;
    int t, x, y;
    int bt=0, bx=0, by=0;

    cin >> N;

    rep (i, N) {
        cin >> t >> x >> y;
        
        int dt = abs(t-bt);
        int dx = abs(x-bx);
        int dy = abs(y-by);

        if ((dt >= dx+dy) && ((dt-dx-dy)%2 == 0)) {
            bt = t;
            bx = x;
            by = y;
            continue;
        } else {
            cout << "No" << endl;
            return 0;
        }
        
    }
    cout << "Yes" << endl;

}
