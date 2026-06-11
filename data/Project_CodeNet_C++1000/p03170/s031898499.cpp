#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(auto &e : A) cin >> e;
    vector<bool> seen(K + 1);
    vector<bool> dp(K + 1);
    auto f = [&](auto &&f, int n) -> bool {
        if(seen[n]) return dp[n];
        for(auto &a : A) {
            if(n - a >= 0 && !f(f, n - a)) dp[n] = true;
        }
        seen[n] = true;
        return dp[n];
    };
    cout << (f(f, K) ? "First" : "Second") << '\n';
}
