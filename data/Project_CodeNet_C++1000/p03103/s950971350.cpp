#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin >> n >> m;
    vector<pair<ll, ll>> drinks;
    for (ll i = 0; i < n; ++i) {
        ll a, b; cin >> a >> b;
        drinks.PB(MP(a, b));
    }
    sort(drinks.begin(), drinks.end());
    ll ans = 0;
    ll curIdx = 0;
    while (m > 0) {
        if (drinks[curIdx].second <= m) {
            m -= drinks[curIdx].second;
            ans += drinks[curIdx].second * drinks[curIdx].first;
        } else {
            ans += m * drinks[curIdx].first;
            m = 0;
        }
        curIdx++;
    }
    cout << ans << "\n";
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* print new lines
*/