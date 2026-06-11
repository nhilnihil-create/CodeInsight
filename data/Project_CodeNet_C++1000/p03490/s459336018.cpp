#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (signed i = 0; i < (n); i++)
#define REP(i, s, n) for (signed i = (s); i < (n); i++)
#define int long long

bool ok(int x, int sum, vector<int> v) {
    int M = sum - abs(x);
    if (M < 0) return false;
    int N = v.size();
    vector<bool> dp(M + 1);
    dp[0] = true;
    
    rep(i, N) v[i] *= 2;
    
    REP(i, 1, N) if(v[i] > 0){
        rep(k, M + 1) {
            int j = M - k;
            if (j - v[i] < 0) continue;
            dp[j] = dp[j] || dp[j - v[i]];
        }
    }
    return dp[M];
}

signed main() {
    string s; cin >> s;
    int n = s.size();
    vector<vector<int>> v{{0},{0}};
    vector<int> sum{0,0};
    bool ver = false;
    rep(i, n) {
        if (s[i] == 'F') {
            v[ver].back() += 1;
        } else {
            sum[ver] += v[ver].back();
            ver = !ver;
            v[ver].push_back(0);
        }
    }
    sum[ver] += v[ver].back();
    
    int x, y; cin >> x >> y;
    bool ans = ok(x - v[0][0], sum[0] - v[0][0], v[0]) && ok(y, sum[1], v[1]);
    cout << (ans ? "Yes" : "No") << endl;
}