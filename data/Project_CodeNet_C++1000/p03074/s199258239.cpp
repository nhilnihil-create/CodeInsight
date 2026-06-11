#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
using ld = long double;
ll mod = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> array;
    if (s[0] == '0') {
        array.push_back(0);
    }
    ll count = 1;
    repd(i, 1, n) {
        if (s[i - 1] != s[i]) {
            array.push_back(count);
            count = 0;
        }
        count++;
    }
    array.push_back(count);
    if (array.size() % 2 == 0) {
        array.push_back(0);
    }

    if (array.size() <= 2 * k + 1) {
        cout << n << endl;
        return 0;
    }
    ll ans = 0;
    ll sum = 0;
    rep(i, 2 * k + 1) { sum += array[i]; }
    ans = max(ans, sum);

    ll num = (array.size() - (2 * k + 1)) / 2;
    rep(i, num) {
        sum -= array[2 * i] + array[2 * i + 1];
        sum += array[2 * k + 1 + 2 * i] + array[2 * k + 2 + 2 * i];
        ans = max(ans, sum);
    }

    cout << ans << endl;

    return 0;
}

