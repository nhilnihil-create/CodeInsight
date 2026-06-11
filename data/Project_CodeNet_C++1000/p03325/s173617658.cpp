#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int div_times(ll a, int n) {
    int count = 0;
    while (a % n == 0) {
        a /= n;
        count += 1;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += div_times(a[i], 2);
    }
    cout << ans << endl;
    return 0;
}