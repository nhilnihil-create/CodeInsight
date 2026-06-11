#include "bits/stdc++.h"

using namespace std;

void Main() {
    long long N, K;
    cin >> N >> K;
    vector<pair<long long, long long>> ps(N, make_pair(0, 0));
    vector<long long> X(N, 0), Y(N, 0);
    for (long long i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;
        ps[i].first = x;
        ps[i].second = y;
        X[i] = x;
        Y[i] = y;
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    long long ans = 2000000000LL * 2000000000LL + 10LL;
    for (long long i = 0; i < N - 1; ++i) {
        for (long long j = 0; j < N - 1; ++j) {
            long long x0 = X[i];
            long long y0 = Y[j];
            bool less = false;
            for (long long in = i + 1; in < N; ++in) {
                for (long long jn = j + 1; jn < N; ++jn) {
                    long long xn = X[in];
                    long long yn = Y[jn];
                    long long np = 0;
                    bool ok = true;
                    for (long long p = 0; p < N; ++p) {
                        long long x = ps[p].first;
                        long long y = ps[p].second;
                        if (x0 <= x && x <= xn && y0 <= y && y <= yn) {
                            ++np;
                            if (np > K) {
                                ok = false;
                                break;
                            }
                        }
                    }
                    if (ok && np == K) {
                        ans = min(ans, (xn - x0) * (yn - y0));
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
