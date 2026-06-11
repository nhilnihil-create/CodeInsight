#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (signed i = 0; i < (n); i++)
#define REP(i, s, n) for (signed i = (s); i < (n); i++)
#define int long long

signed main() {
    int N; cin >> N;
    vector<int> a(N), b(N);
    rep(i, N) cin >> a[i];
    rep(i, N) cin >> b[i];
    
    vector<int> aa(N), bb(N);
    int ans = 0;
    rep(k, 29) {
        int mod = 1 << (k + 1);
        rep(i, N) {
            aa[i] = a[i] % mod;
            bb[i] = b[i] % mod;
        }
        
        sort(bb.begin(), bb.end());
        int sum = 0;
        rep(i, N) {
            {
                int l = (1 << k) - aa[i], r = 2 * (1 << k) - aa[i];
                sum += lower_bound(bb.begin(), bb.end(), r) - lower_bound(bb.begin(), bb.end(), l);
            }
            {
                int l = 3 * (1 << k) - aa[i], r = 4 * (1 << k) - aa[i];
                sum += lower_bound(bb.begin(), bb.end(), r) - lower_bound(bb.begin(), bb.end(), l);
            }
        }
        ans |= (sum & 1) << k;
    }
    cout << ans << endl;
}