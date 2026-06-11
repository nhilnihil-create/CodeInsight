#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll k;

ll pow10(int x) {
    ll ret = 1;
    rep(i,x) ret *= 10;
    return ret;
}

int main() {
    cin >> k;
    ll now = 1;
    ll cnt = 1;
    int r = 0;
    while (k > 0) {
        cout << now << endl;
        double best = 1000000000000000000000.0;
        ll nxt;
        rep(i,20) {
            ll p = pow10(i);
            ll tmp = now+p;
            ll _tmp = tmp;
            ll cnt2 = 0;
            while (_tmp) {
                cnt2 += _tmp%10;
                _tmp /= 10;
            }
            if (best > tmp/(double)cnt2) {
                best = tmp/(double)cnt2;
                cnt = cnt2;
                nxt = tmp;
            }
        }
        now = nxt;
        k--;
    }
}

