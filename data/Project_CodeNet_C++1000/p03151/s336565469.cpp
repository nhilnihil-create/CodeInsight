#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> d;
    ll suma = 0;
    ll sumb = 0;
    rep(i, n) {
        cin >> a[i];
        suma += (ll) a[i];
    }
    rep(i, n) {
        cin >> b[i];
        sumb += (ll) b[i];
    }
    if(sumb > suma) {
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    ll s = 0;
    rep(i, n) {
        if(a[i] < b[i]) {
            ans++;
            s += (ll) b[i] - (ll) a[i];
        }
        else {
            d.push_back(a[i] - b[i]);
        }
    }
    ll k = 0;
    sort(d.rbegin(),d.rend());
    int j = 0;
    while(k < s) {
        k += (ll) d[j];
        j++;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
