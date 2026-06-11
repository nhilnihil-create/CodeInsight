#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    int cx = 0, cy = 0, ct = 0;
    REP(i, N) {
        int t, x, y;
        cin >> t >> x >> y;
        int d = abs(cx - x) + abs(cy - y);
        if (d > t - ct || d % 2 != (t - ct) % 2) {
            cout << "No" << endl;
            return 0;
        }
        cx = x; cy = y; ct = t;
    }
    cout << "Yes" << endl;
}