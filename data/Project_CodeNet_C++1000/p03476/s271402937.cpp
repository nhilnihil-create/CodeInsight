#include <bits/stdc++.h>
#define MAX_N 110000
using namespace std;
using ll = long long;
int main() {
    int q;
    cin >> q;
    vector<int> nums;
    vector<bool> is_prime(MAX_N, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i < MAX_N; i++) {
        if (!is_prime[i]) continue;
        if (is_prime[(i+1)/2] && i % 2 == 1) nums.push_back(i);
        for (ll j = i * i; j < MAX_N; j += i) {
            is_prime[j] = false;
        }
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        auto ans = upper_bound(nums.begin(), nums.end(), r) - lower_bound(nums.begin(), nums.end(), l);
        cout << ans << endl;
    }
    return 0;
}