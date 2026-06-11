#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> x(N), y(N), h(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i] >> h[i];
    for (int cx = 0; cx <= 100; cx++) {
        for (int cy = 0; cy <= 100; cy++) {
            int H = -1;
            bool ok = true;
            for (int i = 0; i < N; i++) {
                if (h[i] > 0) {
                    int tmp = h[i] + abs(x[i] - cx) + abs(y[i] - cy);
                    if (H == -1) H = tmp;
                    else if (H != tmp) {
                        ok = false;
                        break;
                    }
                }
            }
            if (!ok) continue;
            for (int i = 0; i < N; i++) {
                if (h[i] == 0) {
                    if (H - abs(x[i] - cx) - abs(y[i] - cy) > 0) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                cout << cx << " " << cy << " " << H << endl;
                return 0;
            }
        }
    }
}