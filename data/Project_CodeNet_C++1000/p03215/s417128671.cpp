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
const double PI = acos(-1);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<ll> v;
    for (int i = 0; i < n; i++) {
        ll sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            v.push_back(sum);
        }
    }

    ll res = 0;
    for (int i = 40; i >= 0; i--) {
        int cnt = 0;
        vector<ll> next;
        for (auto &x: v) {
            if (x & (1ll << i)) {
                next.push_back(x);
                cnt++;
            }
        }

        if (cnt >= k) {
            v = next;
            res |= 1ll << i;
        }
    }
    cout << res << endl;
}
