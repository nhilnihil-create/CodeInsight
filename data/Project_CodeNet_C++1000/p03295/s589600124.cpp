#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> E(M);
    for (int i = 0; i < M; ++i) cin >> E[i].first >> E[i].second;
    sort(E.begin(), E.end());

    int ans = 1;
    int right = E[0].second;
    for (int i = 1; i < M; ++i) {
        int left = E[i].first;
        if (right <= left) {
            ++ans;
            right = E[i].second;
        } else {
            right = min(right, E[i].second);
        }
    }
    cout << ans << endl;
}
