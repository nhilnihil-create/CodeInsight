//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;



int main() {
    int n;
    cin >> n;
    vi a(n), b(n), c(n);
    rep(i, n) {
        cin >> a[i];
    }
    rep(i, n) {
        cin >> b[i];
    }
    rep(i, n) {
        cin >> c[i];
    }

    sort(all(a));
    sort(all(b));
    sort(all(c));

    vector<ll> dd(n);
    rep(i, n) {
        vi::iterator itr = upper_bound(all(c), b[i]);
        dd[i] = distance(itr, c.end());
    }

    
    rep(i, n-1) {
        dd[n-2-i] += dd[n-1-i];
    }


    ll ans = 0LL;
    rep(i, n) {
        vi::iterator itr = upper_bound(all(b), a[i]);
        int num = distance(b.begin(), itr);
        if(num == n) continue;
        ans += dd[num];
    }

    cout << ans << endl;
}