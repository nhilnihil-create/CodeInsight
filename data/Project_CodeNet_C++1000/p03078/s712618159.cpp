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
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vi a(x), b(y), c(z);
    rep(i, x) {
        cin >> a[i];
    }
    rep(i, y) {
        cin >> b[i];
    }
    rep(i, z) {
        cin >> c[i];
    }

    
    sort(rall(c));

    vi ab;

    rep(i, x) {
        rep(j, y) {
            ab.push_back(a[i] + b[j]);
        }
    }

    sort(rall(ab));

    rep(i, x*y-k) {
        ab.pop_back();
    }

    vi abc;
    rep(i, min(x*y, k)) {
        rep(j, z) {
            abc.push_back(ab[i] + c[j]);
        }
    }

    sort(rall(abc));
    rep(i, k) {
        cout << abc[i] << endl;
    }
}