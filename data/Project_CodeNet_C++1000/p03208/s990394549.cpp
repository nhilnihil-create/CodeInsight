#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main() {
    int N, K, result = 2000000000, tmp;
    cin >> N >> K;
    vector<int> h(N);
    REP(i, N) {
        cin >> h[i];
    }
    sort(ALL(h));
    REP(i, N-K+1) {
        tmp = h[i+K-1] - h[i];
        if (tmp < result) {
            result = tmp;
        }
    }
    cout << result << endl;
    return 0;
}
