#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)

int main() {
    int N; cin >> N;
    vector<int> D(N);
    rep(i, 0, N) cin >> D[i];
    sort(D.begin(), D.end());
    function<int(int, int)> calc = [&](int a, int b) {
        int res = abs(a - b);
        if(res > 12) res = 24 - res;
        return res;
    };
    function<int(int)> solve = [&](int d) {
        vector<int> T;
        T.push_back(0);
        rep(i, 0, N) {
            if((i + d) % 2) T.push_back(D[i]);
            else T.push_back(24 - D[i]);
        }
        int res = 12;
        rep(i, 0, N) rep(j, i + 1, N + 1) {
            res = min(res, calc(T[i], T[j]));
        }
        return res;
    };
    cout << max(solve(0), solve(1)) << endl;
    return 0;
}
