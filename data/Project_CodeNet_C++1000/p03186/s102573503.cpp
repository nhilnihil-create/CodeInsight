#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = min(a, c);
    c -= a;
    if (c < 0) {
        cout << ans + b << endl;
    } else {
        cout << ans + b + min(b + 1, c) << endl;
    }
}
