#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rrep(i, n) for(int i=n-1; i>=0; i--)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n, a[200010];

int main() {
    cin >> n;
    rep(i, n) cin >> a[i];

    ll ans = 0, sum = 0, xors = 0;
    int r = 0;
    rep(l, n) {
        while (r < n && (xors ^ a[r]) == (sum + a[r])) {
            sum += a[r];
            xors ^= a[r];
            r++;
        }
        ans += r - l;
        if (r == l) r++;
        else {
            sum -= a[l];
            xors ^= a[l];
        }
    }
    cout << ans << endl;
}
