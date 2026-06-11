#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int N;

int main() {
    cin >> N;
    vector<long long> A(1 << N);
    for (int i = 0; i < (1 << N); i++) {
        cin >> A[i];
    }
    int size = (1 << N);
    vector<vector<pair<long long, int>>> z(size);

    long long idx;
    for (int j = 0; j < (1 << N); j++) {
        z[j].push_back({A[j], j});
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (1 << N); j++) {
            if (!(j & (1 << i))) {
                idx = j | (1 << i);
                for (auto p : z[j]) {
                    z[idx].push_back(p);
                }
                if (z[idx].size() > 2) {
                    sort(z[idx].begin(), z[idx].end());
                    z[idx].erase(z[idx].begin(), z[idx].end() - 2);
                }
            }
        }
    }

    long long ans = 0;
    for (int k = 1; k < (1 << N); k++) {
        long long value = 0;
        for (auto p : z[k]) {
            value += p.first;
        }
        ans = max(ans, value);
        cout << ans << endl;
    }
    return 0;
}
