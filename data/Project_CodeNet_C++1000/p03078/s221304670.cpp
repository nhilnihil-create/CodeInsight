#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    rep(i, x) cin >> a[i];
    rep(i, y) cin >> b[i];
    rep(i, z) cin >> c[i];
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());
    sort(c.begin(), c.end(), greater<ll>());
        
    vector<ll> abc;
    rep(ai, x) {
        rep(bi, y) {
            if (ai * bi > k) break;
            rep(ci, z) {
                if (ai * bi * ci > k) break;
                abc.push_back(a[ai] + b[bi] + c[ci]);
            }
        }
    }
    sort(abc.begin(), abc.end(), greater<ll>());
    rep(i, k) cout << abc[i] << endl; 
    return 0;
}