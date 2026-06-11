#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
#define ALL(v) v.begin(), v.end()
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define chmax(x, a) x = max(x, a)
#define chmin(x, a) x = min(x, a)

int main() {
    string s;
    cin >> s;
    ll N = s.length();
    ll cnt = 0;
    ll ans = 0;
    for (ll i = N-1; i >= 0; i--) {
        if (s[i] == 'B') {
            ans += N-i-1-cnt;
            cnt++;
        }
    }
    cout << ans << endl;
}
