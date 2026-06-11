#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ll n, k; cin >> n >> k;

    ll ans = 0;
    for (int i = 0; i <=n ; ++i) {
        if (i - 1 >= k) {
            ans += n / i * max(0ll, (i - k));
            ans += max(0ll, (n % i) - k + 1);
        }
    }

    if (k == 0) ans -= n;
    cout << ans << endl;
}