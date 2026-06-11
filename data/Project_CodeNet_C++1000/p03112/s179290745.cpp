#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e15;

int main() {
    ll A, B, Q; cin >> A >> B >> Q;
    vector<ll> s(A); for (int i = 0; i < A; i++) cin >> s[i];
    vector<ll> t(B); for (int i = 0; i < B; i++) cin >> t[i];
    for (int i = 0; i < Q; i++) {
        ll x; cin >> x;
        ll sl, sr;
        if (s[0] < x) {
            int ok = 0, ng = A;
            while (ng - ok != 1) {
                int med = (ng + ok) / 2;
                if (s[med] < x) {
                    ok = med;
                } else {
                    ng = med;
                }
            }
            if (ok == A-1) {
                sl = x - s[ok];
                sr = INF;
            } else {
                sl = x - s[ok];
                sr = s[ok+1] - x;
            }
        } else {
            sl = INF, sr = s[0] - x;
        }
        ll tl, tr;
        if (t[0] < x) {
            int ok = 0, ng = B;
            while (ng - ok != 1) {
                int med = (ng + ok) / 2;
                if (t[med] < x) {
                    ok = med;
                } else {
                    ng = med;
                }
            }
            if (ok == B-1) {
                tl = x - t[ok];
                tr = INF;
            } else {
                tl = x - t[ok];
                tr = t[ok+1] - x;
            }
        } else {
            tl = INF, tr = t[0] - x;
        }
        cout << min(min(max(sl, tl), max(sr, tr)), min(min(sl, tr)*2 + max(sl, tr), min(sr, tl)*2 + max(sr, tl))) << endl;
    }
}
