#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    vector<ll> dp(1<<n, 0);
    auto compute = [&](int num) -> ll {
        vector<int> idx;
        for(int i = 0; i < n; i++) {
            if ((num >> i) & 1) {
                idx.push_back(i);
            }
        }
        ll res = 0;
        for(int i = 0; i < idx.size(); i++)
            for(int j = i+1; j < idx.size(); j++)
                res += mat[idx[i]][idx[j]];
        return res;
    };
    auto sub = [&](auto self, vector<int>& arr, int d, int sub, int orig) -> ll {
        if (d == arr.size()) {
            int tmp = (orig ^ sub);
            // printf("num %d = (%d, %d)\n", orig, sub, tmp);
            return dp[tmp] + dp[sub];
        }
        ll res1 = self(self, arr, d+1, sub, orig);
        ll res2 = self(self, arr, d+1, sub+(1<<arr[d]), orig);
        return max(res1, res2);
    };
    ll ans = 0;
    for(int state = 0; state < (1<<n); state++) {
        dp[state] = max(dp[state], compute(state));
        vector<int> idx;
        for(int i =0 ; i < n; i++) {
            if ((state >> i) & 1) {
                idx.push_back(i);
            }
        }
        if (idx.size() > 0)
            dp[state] = max(dp[state], sub(sub, idx, 0, 0, state));
        ans = max(ans, dp[state]);
    }
    cout << ans << endl;
    return 0;
}


