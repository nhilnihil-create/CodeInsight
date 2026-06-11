//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vi = vector<ll>;
using vvi = vector<vi>;



int main() {
    int n;
    cin >> n;
    vi a(n);
    vi b(n);

    rep(i, n) {
        int a_, b_; 
        cin >> a_ >> b_;
        b[i] = b_;
        a[i] = a_+b_;
    }

    sort(rall(a));

    ll ans = 0LL;
    rep(i, n) {
        if(!(i&1)) {
            ans += a[i];
        }
        ans -= b[i];
    }

    cout << ans << endl;
}