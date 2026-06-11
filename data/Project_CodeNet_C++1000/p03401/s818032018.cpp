#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define inf LLONG_MAX
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


int main()
{
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    a.insert(a.begin(), 0);
    a.push_back(0);
    // for (auto elem : a) cout << elem << " "; cout << endl;

    vector<ll> ls(n+1);
    rep(i, n+1) {
        ls[i] = abs(a[i+1] - a[i]);
        if (i != 0) ls[i] += ls[i-1];
    }
    ls.insert(ls.begin(), 0);
    // for (auto elem : ls) cout << elem << " "; cout << endl;

    rep (i, n) {
        ll num = ls[i];
        num += abs(a[i+2] - a[i]);
        num += ls[ls.size()-1] - ls[i+2];

        cout << num << endl;
    }
/*     vector<ll> b(a.begin(), a.end());
    sort(all(b));
    ll max_num = b[b.size()-1], min_num = b[0];

    rep(i, n) {
        ll num = a[i];
        if (num == min_num) {
            cout << max(0LL, -b[1]) * 2 + max_num * 2 << endl;
        } else if (num == max_num) {
            cout << -min_num * 2 + max(0LL, b[b.size()-2]) * 2 << endl;
        } else {
            cout << (max_num - min_num) * 2 << endl;
        }
    }
 */
    return 0;
}