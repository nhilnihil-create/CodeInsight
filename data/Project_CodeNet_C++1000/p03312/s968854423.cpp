#include<bits/stdc++.h>
using namespace std;

int main(void) {
    long n;
    cin >> n;

    vector<long> a(n);
    for(auto &e: a) cin >> e;

    vector<long> b(n+1);
    for(long i=1; i<=n; i++)
        b[i] = b[i-1] + a[i-1];


    long r = 1e18;
    for(long i=2; i<=n-2; i++) {
        // 0 1 ... i-1 | i ... n-1
        long ls = b[i], rs = b[n] - b[i];
        for(long lls : {
                *prev(upper_bound(b.begin(), b.begin()+i+1, ls/2)),
                *lower_bound(b.begin(), b.begin()+i+1, ls/2),
                })
        for(long rls : {
                *prev(upper_bound(b.begin()+i+1, b.end(), ls + rs/2)) - ls,
                *lower_bound(b.begin()+i+1, b.end(), ls + rs/2) - ls,
                }) {
            long lrs = ls - lls;
            long rrs = rs - rls;

            long mx = max({lls, lrs, rls, rrs});
            long mn = min({lls, lrs, rls, rrs});

            r = min(r, mx-mn);
        }
    }
    cout << r << endl;
}
