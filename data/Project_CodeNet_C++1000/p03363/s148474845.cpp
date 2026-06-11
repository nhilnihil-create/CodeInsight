#include <iostream>
#include <algorithm>
#include <map>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;


int main(void) {
    int n, i;
    ll a[200003] = {};
    map<ll, ll> m;

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (i = 1; i <= n; i++) {
        a[i] += a[i - 1];
    }

    for (i = 0; i <= n; i++) {
        m[a[i]]++;
    }

    map <ll, ll>::iterator ite;
    ll ans = 0;
    for (ite = m.begin(); ite != m.end(); ite++) {
        ans += ite->second * (ite->second - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}