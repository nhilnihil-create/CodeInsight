#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = std::pair<int, int>;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pb push_back
const int mn = 1e6 + 5;
int n, k;
int a[mn];
ll s[mn];
vector<ll> b;

int main() {
#ifdef trote
    freopen("../1.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), s[i] = s[i - 1] + a[i];
    for (int l = 0; l <= n; l++) {
        for (int r = l + 1; r <= n; r++) {
            b.pb(s[r] - s[l]);
        }
    }
    //printf("%d\n", sz(b));
    ll ans = 0;
    for (int i = 50; i >= 0; i--) {
        vector<ll> t;
        for (auto &v:b) {
            if (v & (1ll << i)) {
                t.pb(v);
            }
        }
        if (sz(t) >= k) {
            swap(b, t);
            ans |= (1ll << i);
        }
    }
    printf("%lld\n", ans);
    return 0;
}