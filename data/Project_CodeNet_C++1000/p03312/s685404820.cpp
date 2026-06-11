#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), prefix_sum(n + 1, 0);
    rep(i, n) {
        cin >> a[i];
        prefix_sum[i + 1] = prefix_sum[i] + a[i];
    }
    ll ans = 1e18;
    int left = 1, right = 3;
    for (int mid = 2; mid < n; mid++) {
        while(left + 1 < mid && abs(prefix_sum[mid] - prefix_sum[left] - prefix_sum[left]) > abs(prefix_sum[mid] - prefix_sum[left+1] - prefix_sum[left+1])){
            left++;
        }
        while(right + 1 <= n && abs(prefix_sum[n] - prefix_sum[right] - (prefix_sum[right] - prefix_sum[mid])) > abs(prefix_sum[n] - prefix_sum[right+1] - (prefix_sum[right+1] - prefix_sum[mid]))){
            right++;
        }
        ll b = prefix_sum[left];
        ll c = prefix_sum[mid] - prefix_sum[left];
        ll d = prefix_sum[right] - prefix_sum[mid];
        ll e = prefix_sum[n] - prefix_sum[right];
        ans = min(ans, max({b, c, d, e}) - min({b, c, d, e}));
    }
    cout << ans << endl;
}