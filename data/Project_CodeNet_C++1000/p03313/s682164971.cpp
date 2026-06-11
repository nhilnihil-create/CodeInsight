// ARC100-C Or Plus Max

#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> pll;
const long long INF = 1LL << 60;

void chmax(pll &a, pll b);

signed main() {
    int N;
    cin >> N;

    vector<long long> A(1<<N);
    vector<pll> dp(1<<N);

    for(int bit = 0; bit < (1<<N); bit++ ) {
        cin >> A[bit];
        dp[bit] = {A[bit], -INF};
    }

    for(int i = 0; i < N; i++ ) {
        for(int bit = 0; bit < (1<<N) ;bit++ ) {
            if(bit & (1<<i) ) {
                chmax(dp[bit], dp[bit^(1<<i)] );
            }
        }
    }

    long long res = -INF;

    for(int bit = 0; bit < (1<<N); bit++ ) {
        long long tmp = dp[bit].first + dp[bit].second;
        res = max(res, tmp);

        if(bit) {
            cout << res << '\n';
        }
    }

    return (0);
} 

void chmax(pll &a, pll b) {
    if(a.first < b.first) {
        a.second = max(a.first, b.second);
        a.first = b.first;
    } 
    else {
        a.second = max(a.second, b.first);
    }

    return ;
}