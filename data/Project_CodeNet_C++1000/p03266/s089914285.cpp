#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
int main() {
    ll n, k;
    cin >> n >> k;
    ll cnt = n / k;
    ll ans = cnt * cnt * cnt;
    if (k % 2 == 0) {
        cnt = (n + k / 2) / k;
        ans += cnt * cnt * cnt;
    }
    cout << ans;
    return 0;
}