#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rep1(i, n) for(int i=1; i<=n; i++)
#define repr(i, n) for(int i=n-1; i>=0; i--)
#define repr1(i, n) for(int i=n; i>=1; i--)
#define all(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int n; cin >> n;
    vector<string> v(n);
    rep(i, n) cin >> v[i];

    int ans = 0;
    for (auto s: v) {
        rep(i, s.size() - 1) {
            if (s[i] == 'A' && s[i+1] =='B') ans++;
        }
    }

    int c1 = 0, c2 = 0, c3 = 0;
    for (auto s: v) {
        if (s.front() == 'B' && s.back() == 'A') c1++;
        if (s.front() == 'B' && s.back() != 'A') c2++;
        if (s.front() != 'B' && s.back() == 'A') c3++;
    }

    if (c1 == 0) ans += min(c2, c3);
    else {
        if (c2 + c3 > 0) ans += c1 + min(c2, c3);
        else ans += c1 - 1;
    }
    cout << ans << endl;
}
