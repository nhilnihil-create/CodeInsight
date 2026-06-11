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
    ll mod = 1e9 + 7, ans = 0;
    vector<ll> arr(n, 0);
    vector<ll> dp(n, 1);
    for(auto& val: arr)
        cin >> val;
    unordered_map<ll, int> pos;
    pos[arr[0]] = 0;
    for(int i = 1; i < n; i++) {
        dp[i] = dp[i-1];
        if (pos.count(arr[i]) > 0 && pos[arr[i]] != i-1) {
            dp[i] += dp[pos[arr[i]]];
        }
        dp[i] %= mod;
        pos[arr[i]] = i;
    }
    cout << dp.back() << endl;
    return 0;
}


