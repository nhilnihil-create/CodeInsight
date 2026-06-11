#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
 
typedef long long ll;

int main() {
    int A, B, Q;
    cin >> A >> B >> Q;
    vector<ll> s(A + 2), t(B + 2), x(Q);
    s[0] = -1e11;
    t[0] = -1e11;
    s[A + 1] = 1e11;
    t[B + 1] = 1e11;
    rep(i, A) cin >> s[i + 1];
    rep(i, B) cin >> t[i + 1];
    rep(i, Q) cin >> x[i];
    rep(i, Q) {
        ll ans = 1e18;
        int j = upper_bound(s.begin(), s.end(), x[i]) - s.begin();
        int k = upper_bound(t.begin(), t.end(), x[i]) - t.begin();
        //cout << "i=" << i << " j=" << j << " k=" << k << endl;
        ll d = s[j] - x[i];
        if (t[k] > s[j]) d = t[k] - x[i];
        //cout << "d=" << d << endl;
        if (d < ans) ans = d;
        d = x[i] - s[j - 1];
        if (t[k - 1] < s[j - 1]) d = x[i] - t[k - 1];
        //cout << "d=" << d << endl;
        if (d < ans) ans = d;
        d = s[j] - x[i] + s[j] - t[k - 1];
        //cout << "d=" << d << endl;
        if (d < ans) ans = d;
        d = x[i] - t[k - 1] + s[j] - t[k - 1];
        //cout << "d=" << d << endl;
        if (d < ans) ans = d;
        d = t[k] - x[i] + t[k] - s[j - 1];
        //cout << "d=" << d << endl;
        if (d < ans) ans = d;
        d = x[i] - s[j - 1] + t[k] - s[j - 1];
        //cout << "d=" << d << endl;
        if (d < ans) ans = d;
        cout << ans << endl;
    }
}