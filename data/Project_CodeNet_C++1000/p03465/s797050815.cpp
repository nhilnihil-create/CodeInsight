#include <bits/stdc++.h>
using namespace std;

constexpr int max_v = 4000000;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    bitset<max_v + 1> dp;
    dp[0] = 1;
    for(int i = 0; i < n; ++i) {
        dp = (dp << a[i]) | dp;
    }
    int ans = 0;
    for(int i = (sum + 1) / 2; i <= max_v; ++i) {
        if(dp[i]) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;
}