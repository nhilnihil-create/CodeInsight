#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n; cin >> n;
    vector<int> a(1 << n);
    for(int i = 0; i < (1 << n); ++i) {
        cin >> a[i];
    }

    vector<int> dp(1 << n);
    for(int S = 1; S < (1 << n); ++S) {
        int max_v = -1e9;
        for(int T = S; ; T = (T - 1) & S) {
            dp[S] = max(dp[S], a[T] + max_v);
            max_v = max(max_v, a[T]);
            if(T == 0) break;
        }
    }
    for(int i = 1; i < (1 << n); ++i) {
        dp[i] = max(dp[i], dp[i - 1]);
    }

    for(int i = 1; i < (1 << n); ++i) {
        cout << dp[i] << endl;
    }
}