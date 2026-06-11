#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> X(N), Y(N), H(N); int x, y, h;
    REP(i, 0, N) {
        cin >> X[i] >> Y[i] >> H[i];
        if (H[i] > 0) {
            x = X[i]; y = Y[i]; h = H[i];
        }
    }

    REP(i, 0, 101) {
        REP(j, 0, 101) {
            bool ok = true;
            int height = h + abs(i - x) + abs(j - y);
            REP(k, 0, N) {
                if (max(height - abs(i - X[k]) - abs(j - Y[k]), 0) != H[k]) {
                    ok = false; break;
                }
            }
            if (ok) {
                cout << i << " " << j << " " << height << endl;
            }
        }
    }
    return 0;
}