#include<iostream>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    ll k, a, b;
    cin >> k >> a >> b;

    ll ans = 0;
    if (b <= a + 2) ans = k + 1;
    else {
        if (k <= a-1) ans = k;
        else {
            ans = a;
            k -= a - 1; // a枚たまった時の残りターン
            if (k % 2 == 0) ans +=  k / 2 * (b - a);
            else ans += k / 2 * (b - a) + 1;
        }
    }

    cout << ans << endl;
}