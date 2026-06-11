#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

bool prime_num(ll x) {
    if (x == 1) return false;
    else if (x == 2) return true;
    else if (x % 2 == 0) return false;
    else {
        for (ll i = 3; i*i <= x; i += 2) {
            if (x % i == 0) return false;
        }
    }
    return true;
}

int main()
{
    ll n, p;
    cin >> n >> p;

    ll ans = 1;
    bool x[1000003] = {};
    if (n == 1) {
        cout << p << endl;
        return 0;
    }
    if (n >= 40) {
        cout << 1 << endl;
        return 0;
    }
    if (prime_num(p)) {
        if (n == 1) ans = p;
        else ans = 1;
        cout << ans << endl;
        return 0;
    } else {
        for (int i = 1; i <= 1000002; i++) {
            ll y = pow(i, n);
            if (y > p) break;
            if (p % y == 0) x[i] = true;
        }
        for (int i = 1000002; i >= 1; i--) {
            if (x[i]) {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
        return 0;
    }


}
