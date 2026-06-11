//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<ll, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n;
    ll z, w;
    cin >> n >> z >> w;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    vector<P> b(n), s(n);
    if(n != 1) {
        b[n-2].first = abs(a[n-1]-a[n-2]);
        b[n-2].second = n-2;
        s[n-2] = b[n-2];
    }
    for(int i = n-3; i>=0; --i) {
        if(abs(a[i]-a[n-1]) > b[i+1].first) {
            b[i] = P(abs(a[i]-a[n-1]), i);
        } else {
            b[i] = b[i+1];
        }
        if(abs(a[i]-a[n-1]) < s[i+1].first) {
            s[i] = P(abs(a[i]-a[n-1]), i);
        } else {
            s[i] = s[i+1];
        }
    }
    b[n-1].first = -1;
    s[n-1].first = LINF;

    int i = 0;
    int f = 0;
    ll ans = abs(w-a[n-1]);
    while(f != n) {
        if(!(i&1)) {
            if(abs(w-a[n-1]) < b[f].first) {
                z = a[b[f].second];
                f = b[f].second+1;
            } else {
                f = n;
                z = a[n-1];
            }
        } else {
            if(abs(z-a[n-1]) > s[f].first) {
                w = a[s[f].second];
                f = s[f].second+1;
            } else {
                f = n;
                w = a[n-1];
            }
        }
        ++i;
    }

    ans = max(ans, abs(z-w));
    cout << ans << endl;
}