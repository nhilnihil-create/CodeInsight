#include "bits/stdc++.h"

using namespace std;

int N, M;
vector<long long> X, Y, Z;

long long greedy(long long signX, long long signY, long long signZ) {
    vector<long long> sorted(N, 0LL);
    for (int i = 0; i < N; ++i) {
        sorted[i] += signX * X[i] + signY * Y[i] + signZ * Z[i];
    }
    sort(sorted.begin(), sorted.end(), greater<long long>());
    long long ret = 0;
    for (int i = 0; i < M; ++i) {
        ret += sorted[i];
    }
    return ret;
}

void Main() {
    cin >> N >> M;
    X = vector<long long>(N, 0LL);
    Y = vector<long long>(N, 0LL);
    Z = vector<long long>(N, 0LL);
    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i] >> Z[i];
    }

    long long ans = greedy(1LL, 1LL, 1LL);
    ans = max(ans, greedy(1LL, 1LL, -1LL));
    ans = max(ans, greedy(1LL, -1LL, 1LL));
    ans = max(ans, greedy(-1LL, 1LL, 1LL));
    ans = max(ans, greedy(1LL, -1LL, -1LL));
    ans = max(ans, greedy(-1LL, 1LL, -1LL));
    ans = max(ans, greedy(-1LL, -1LL, 1LL));
    ans = max(ans, greedy(-1LL, -1LL, -1LL));
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
