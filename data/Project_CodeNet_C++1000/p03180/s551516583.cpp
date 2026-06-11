#include <bits/stdc++.h>

#define ll long long


int main() {
    std::ios::sync_with_stdio(false);
    using namespace std;
    const int max_n = 16;
    int n, A[max_n][max_n];
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> A[i][j];

    vector< vector<ll> > D(n, vector<ll>(1<<n));
    for(int bm = 0; bm < (1<<n); bm++) {
        ll res = 0;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(bm & (1<<i) && bm & (1<<j))
                    res += A[i][j];
        D[0][bm] = res;
    }

    for(int i = 1; i < n; i++) {
        for(int bm = 0; bm < (1<<n); bm++) {
            for(int bn = bm - 1; bn > 0; bn = (bn - 1) & bm)
                if((bn & bm) == bn) {
                    D[i][bm] = max(D[i][bm], D[i - 1][bn] + D[0][bm & (~bn)]);
                }
        }
    }

    ll res = 0;
    for(int i = 0; i < n; i++)
        res = max(res, D[i][(1<<n) - 1]);

    cout << res << "\n";

    return 0;
}
