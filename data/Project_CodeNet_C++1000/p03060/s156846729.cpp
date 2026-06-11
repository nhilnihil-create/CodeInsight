#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;
int main() {
    int N; cin >> N;
    vector<pair<int, int>> P(N);
    int ans = 0;
    for (int i = 0; i < N; ++i) cin >> P[i].first;
    for (int i = 0; i < N; ++i) cin >> P[i].second;
    for (int i = 0; i < N; ++i) {
        int tmp = P[i].first - P[i].second;
        if (tmp >= 0) ans += tmp;
    }
    printf("%d\n", ans);
}
