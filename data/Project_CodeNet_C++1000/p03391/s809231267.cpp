#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
#include <map>
#include <deque>

using namespace std;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef long double ld;

const ll SIZE = 1e6 + 10, S2 = 1e7 * 2, MOD = 1e9 + 7, INF = 1e9 * 1e7 * 100;



int main() {
    fastInp;

    ll n;
    cin >> n;
    ll s = 0;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        s += a[i];
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) ans = max(ans, (s - b[i]));
    }

    cout << ans;

    return 0;
}

