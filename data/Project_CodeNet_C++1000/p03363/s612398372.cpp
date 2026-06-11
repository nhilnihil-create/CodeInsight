#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<ll> s(n + 1);
    map<ll, ll> nums;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        s[i + 1] = s[i] + a;
    }

    for (int i = 0; i < n + 1; i++) {
        nums[s[i]]++;
    }

    ll ans = 0;
    for (auto&& x : nums) {
        ll value = x.second;
        ans += value * (value - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}