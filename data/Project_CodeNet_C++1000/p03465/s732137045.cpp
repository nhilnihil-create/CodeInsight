#include <bits/stdc++.h>
using namespace std;

int solve() {
    int N, T = 0;
    cin >> N;
    vector<int> A(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> A[i];
        T += A[i];
    }
    bitset<4000001> dp;
    dp.set(0);
    for ( int i = 0; i < N; i++ ) {
        dp |= (dp << A[i]);
    }
    int h = (T+1)/2;
    while ( h <= T && dp[h] == 0 ) h++;
    return h;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}