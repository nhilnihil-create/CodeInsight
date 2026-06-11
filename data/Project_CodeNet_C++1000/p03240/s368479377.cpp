#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 105;
int n, x, y, h;
vector<int> a[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> h;
        a[i] = {x, y, h};
    }
    for (int i = 0; i <= 100; ++i) {
        for (int j = 0; j <= 100; ++j) {
            int expect = -1;
            bool ok = true;
            for (int k = 0; k < n; ++k) {
                int x0 = a[k][0], y0 = a[k][1], h0 = a[k][2];
                if (h0 == 0) continue;
                int cur = abs(i - x0) + abs(j - y0) + h0;
                if (expect == -1) {
                    expect = cur;
                } else if (expect != cur){
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            for (int k = 0; k < n; ++k) {
                int x0 = a[k][0], y0 = a[k][1], h0 = a[k][2];
                if (h0 != 0) continue;
                int cur = abs(i - x0) + abs(j - y0);
                if (cur < expect) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << i << ' ' << j << ' ' << expect << endl;
                exit(0);
            }
        }
    }
    cout << "0 0 0" << endl;
    return 0;
}
