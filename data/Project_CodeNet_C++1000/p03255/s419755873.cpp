
#include <algorithm>
#include <iostream>

using namespace std;

constexpr static int MAXN = 3e5;
constexpr static int64_t INF = 1e18;

int64_t N, C;
int64_t x[MAXN], xsum[MAXN];

int64_t calc(int l) {
    // solution using l chains
    // C + 5*x1 + 5*x2 + 7*x3 + ...
    // arrange s.t. coeffs are minimized
    double dsum = 0;
    int64_t isum = 0;
    int i = N, k = 1;
    while (i > 0) {
        int j = max(i - l, 0);
        dsum += 1.0 * (2 * k + 1) * (xsum[i] - xsum[j]);
        if (dsum > INF)
            return INF;
        isum += (2 * k + 1) * (xsum[i] - xsum[j]);
        i = j;
        k++;
    }

    isum += 2 * (xsum[N] - xsum[N - l]);
    isum += C * (l + N);
    return isum;
}

int main() {
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> x[i];
        xsum[i + 1] = xsum[i] + x[i];
    }

    int64_t best = 5 * xsum[N] + 2 * N * C;
    for (int l = 1; l <= N; l++) {
        int64_t val = calc(l);
        if (val < best)
            best = val;
    }
    cout << best << endl;
}
