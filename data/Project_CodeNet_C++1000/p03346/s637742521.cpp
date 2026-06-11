#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int>P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }
    vector<int>idx(N+1);
    for (int i = 0; i < N; ++i) {
        idx[P[i]] = i;
    }
    int cur = 1;
    int ans = 0;
    for (int i = 1; i < N; ++i) {
        if (idx[i] < idx[i+1]) {
            cur++;
        } else {
            ans = max(ans, cur);
            cur = 1;
        }
    }
    ans = max(ans, cur);
    ans = N - ans;
    cout << ans << "\n";
    return 0;
}