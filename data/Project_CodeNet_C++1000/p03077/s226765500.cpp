#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, a, b, c, d, e; cin >> n >> a >> b >> c >> d >> e;
    ll m = min({a, b, c, d, e});
    ll ans;
    if (m >= n) ans = 5;
    else {
        ans = n / m + 5;
        if (m == 1) --ans;
    }
    cout << ans << "\n";
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* print new lines
*/