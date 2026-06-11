#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

int main() {
    vector<int> cost = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    int n, m;
    cin >> n >> m;
    vector<int> used(m, 0);
    unordered_map<int, int> cost2val;
    for(int& val: used) {
        cin >> val;
        cost2val[cost[val]] = max(cost2val[cost[val]], val);
    }

    vector<int> dp(n+1, 0);
    vector<int> trace(n+1, -1);
    trace[0] = 0;
    vector<int> label(n+1, 0);
    int diff, digit;
    for(int i = 1; i <= n; i++) {
        for(auto& p: cost2val) {
            diff = p.first;
            digit = p.second;
            if (i - diff >= 0 && trace[i-diff] != -1) {
                if (dp[i-diff]+1 > dp[i]) {
                    dp[i] = dp[i-diff]+1;
                    trace[i] = i-diff;
                    label[i] = digit;
                }
                if (dp[i-diff]+1 == dp[i]) {
                    if (digit > label[i]) {
                        label[i] = digit;
                        trace[i] = i-diff;
                    }
                }
            }
        }
    }
    int idx = n;
    string ans;
    while (idx != 0) {
        ans += ('0' + label[idx]);
        idx = trace[idx];
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}


