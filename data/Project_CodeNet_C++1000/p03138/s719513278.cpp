//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<ll>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n;
    cin >> n;
    ll k;
    cin >> k;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }

    int num = 64-__builtin_clzll(k);
    if(k == 0) {
        num = 0;
    }

    ll K = 0;
    bool ch = true;

    rep(i_, num) {
        int i = num-1-i_;
        int z = 0, o = 0;
        rep(j, n) {
            if((a[j]>>i)&1) {
                ++o;
            } else {
                ++z;
            }
        }
        if(ch) {
            if((k>>i)&1) {
                if(z<=o) {
                    ch = false;
                }
            } else {
                z -= 1000000;
            }
        }

        K += (1LL<<i)*(o<z);
    }


    ll ans = 0LL;

    rep(i, n) {
        ans += K^a[i];
    }

    cout << ans << endl;
}