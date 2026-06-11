#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF __INT32_MAX__
#define LINF __LONG_LONG_MAX__

int main() {
    int Q;
    cin >> Q;
    vi L(Q), R(Q);
    rep(i, Q) {
        cin >> L[i] >> R[i];
    }

    const int QMAX = 100001;

    vi x(QMAX);
    for (int i = 2; i < QMAX; i++) {
        x[i] += x[i - 1];

        if (i % 2 == 0) {
            continue;
        }

        bool ok = true;

        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                ok = false;
                break;
            }
        }
        int ii = (i + 1) / 2;
        if (((ii * 2 - 1) == i) && ok) {
            for (int j = 2; j <= sqrt(ii); j++) {
                if (ii % j == 0) {
                    ok = false;
                    break;
                }
            }
        }

        if (ok) {
            x[i]++;
        }
    }

    rep(i, Q) {
        cout << (x[R[i]] - x[L[i] - 1]) << endl;
    }
}