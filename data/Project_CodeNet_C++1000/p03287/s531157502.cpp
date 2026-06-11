#include "bits/stdc++.h"

using namespace std;

void Main() {
    long long N, M;
    cin >> N >> M;
    vector<long long> A(N, 0);
    for (long long i = 0; i < N; ++i) {
        cin >> A[i];
    }

    map<long long, set<long long> > residual_index;
    vector<long long> sums(N + 1, 0);
    sums[0] = 0;
    residual_index.insert(make_pair(0, set<long long>()));
    residual_index[0].insert(0);
    for (long long i = 1; i < N + 1; ++i) {
        sums[i] = sums[i - 1] + A[i - 1];

        long long r = sums[i] % M;
        if (residual_index.count(r) == 0) {
            residual_index.insert(make_pair(r, set<long long>()));
        }
        residual_index[r].insert(i);
    }

    long long ans = 0;
    for (auto e : residual_index) {
        long long n = e.second.size();
        if (n >= 2) {
            ans += n * (n - 1) / 2;
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
