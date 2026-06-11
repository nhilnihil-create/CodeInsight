#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

const i64 MOD = 1e9+7;

const i64 INF = 1e18+7;

signed main(){
    string s;
    cin >> s;
    vector<int> v(1, 0);
    for(auto& x : s)
        v.emplace_back(v.back() ^ (1 << (x - 'a')));
    vector<int> dp(1 << 26, MOD);
    dp[0] = 0;
    for(int i = 0; i < v.size(); ++i){
        for(int j = 0; j < 26; ++j)
            dp[v[i] ^ (1 << j)] = min(dp[v[i] ^ (1 << j)], dp[v[i]] + 1);
    }
    cout << max(1, dp[v.back()]) << endl;
}
