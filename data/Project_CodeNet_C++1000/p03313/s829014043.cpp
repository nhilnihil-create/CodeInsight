#include <iostream>
#include <vector>
using namespace std;
using pll = pair<long long, long long>;
const long long INF = 1LL<<60;

void chmax(pll &a, pll b) {
    long long f, s;
    if (a.first >= b.first) f = a.first, s = max(a.second, b.first);
    else f = b.first, s = max(a.first, b.second);
    a = pll(f, s);
}

int main() {
    int N; cin >> N;
    vector<long long> A(1<<N);
    for (int bit = 0; bit < (1<<N); ++bit) cin >> A[bit];

    vector<pll> dp(1<<N);
    for (int bit = 0; bit < (1<<N); ++bit) dp[bit] = pll(A[bit], -INF);
    for (int i = 0; i < N; ++i) {
        for (int bit = 0; bit < (1<<N); ++bit) {
            if (bit & (1<<i)) {
                chmax(dp[bit], dp[bit ^ (1<<i)]);
            }
        }
    }
    vector<long long> res(1<<N, 0);
    res[0] = 0;
    for (int bit = 1; bit < (1<<N); ++bit) {
        res[bit] = max(res[bit-1], dp[bit].first + dp[bit].second);
        cout << res[bit] << endl;
    }
}
    
