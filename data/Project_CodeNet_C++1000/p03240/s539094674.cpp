#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    int n; cin >> n;

    vector<int> x(n);
    vector<int> y(n);
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> h[i];
    }

    for (int cx = 0; cx <= 100; ++cx) {
        for (int cy = 0; cy <= 100; ++cy) {
            int H;
            for (int i = 0; i < n; ++i) {
                if (h[i] != 0) {
                    H = h[i] + abs(x[i] - cx) + abs(y[i] - cy);
                }
            }

            bool ok = true;
            for (int i = 0; i < n; ++i) {
                if (h[i] != max(H - abs(x[i] - cx) - abs(y[i] - cy), 0)) {
                    ok = false;
                }
            }

            if (ok) {
                cout << cx << " " << cy << " " << H << endl;
                return 0;
            }
        }
    }
}