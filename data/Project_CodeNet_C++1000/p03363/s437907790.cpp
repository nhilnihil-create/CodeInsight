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
    vector<int> arr(n, 0);
    for(auto& val: arr)
        cin >> val;
    ll acc = 0, ans = 0;
    unordered_map<ll, int> dp;
    dp[0] = 1;
    for(int val: arr) {
        acc += val;
        ans += dp[acc];
        dp[acc] += 1;
    }
    cout << ans << endl;
    return 0;
}


