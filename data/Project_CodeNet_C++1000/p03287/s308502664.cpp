#include <iostream>
#include <map>
#include <vector>
#define rep(i,n) for(int (i)=0;(i)<(n);++(i))
using namespace std;
using ll = long long;

int main() {
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<ll> s(n + 1, 0);
    rep(i, n) s[i + 1] = s[i] + a[i];

    map<ll, ll> cnt; 
    rep(i, n + 1) cnt[s[i] % m]++;

    ll ans = 0;
    for (auto e: cnt) {
        if (e.second % 2 == 0) ans += e.second / 2 * (e.second - 1);
        else ans += (e.second - 1) / 2 * e.second;
    }
    cout << ans << endl;
}