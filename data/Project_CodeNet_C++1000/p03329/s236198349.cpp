#include <bits/stdc++.h>
using namespace std;

#define FOR(i, l, r) for(size_t i = (l); i < (r); i = i + 1)
#define REP(i, n) FOR(i, 0, n)
using ll = long long;

template <class T>
inline bool chmin(T& a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

template <class T>
inline bool chmax(T& a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int N;
    cin >> N;

    int hoge[3] = {1, 6, 9};
    vector<int> dp(N + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i <= N; i++) {
        // cout << "from " << i << endl;
        for(int j = 0; j < 3; j++) {
            int k = 1;
            while((i + int(pow(hoge[j], k)) <= N) && !(j == 0 && k == 2)) {
                // cout << "using " << hoge[j] << "^" << k << "=" << pow(hoge[j], k) << endl;
                if(i + pow(hoge[j], k) == N) {
                    // cout << "to " << i + pow(hoge[j], k) << " ... " << dp[i + pow(hoge[j], k)] << "vs " << dp[i] << "+" << 1 << "=" << dp[i] + 1 << endl;
                }
                chmin(dp[i + pow(hoge[j], k)], dp[i] + 1);
                k++;
            }
        }
    }
    // for(int i = 0; i <= N; i++) {
    // cout << i << ":" << dp[i] << endl;
    // }
    cout << dp[N] << endl;
    return 0;
}