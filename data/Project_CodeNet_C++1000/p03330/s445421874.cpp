#include "bits/stdc++.h"

using namespace std;

void Main() {
    long long N, C;
    cin >> N >> C;

    vector<vector<long long>> D(C, vector<long long>(C, 0));
    for (long long i = 0; i < C; ++i) {
        for (long long j = 0; j < C; ++j) {
            cin >> D[i][j];
        }
    }
    map<long long, map<long long, long long>> cmap;
    cmap.emplace(0, map<long long, long long>());
    cmap.emplace(1, map<long long, long long>());
    cmap.emplace(2, map<long long, long long>());
    for (long long i = 0; i < N; ++i) {
        for (long long j = 0; j < N; ++j) {
            long long c;
            cin >> c;
            --c;
            long long g = (i + j) % 3;
            if (cmap[g].count(c) == 0) {
                cmap[g].emplace(c, 0);
            }
            cmap[g][c] += 1;
        }
    }

    long long ans = 1000000000000000000LL;
    for (long long i = 0; i < C; ++i) {
        for (long long j = 0; j < C; ++j) {
            if (i == j) {
                continue;
            }
            for (long long k = 0; k < C; ++k) {
                if (i == k || j == k) {
                    continue;
                }

                long long diff = 0;
                for (auto e : cmap[0]) {
                    if (e.first != i) {
                        diff += e.second * D[e.first][i];
                    }
                }
                for (auto e : cmap[1]) {
                    if (e.first != j) {
                        diff += e.second * D[e.first][j];
                    }
                }
                for (auto e : cmap[2]) {
                    if (e.first != k) {
                        diff += e.second * D[e.first][k];
                    }
                }
                ans = min(ans, diff);
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
