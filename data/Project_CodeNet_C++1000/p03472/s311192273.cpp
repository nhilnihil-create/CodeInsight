#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 100000000;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll n, h;
    cin >> n >> h;
    vector<ll> a(n), b(n);
    rep1(i, n) cin >> a[i] >> b[i];
    ll ans = 0;
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());
    ll cnt = a[0];
    rep1(i, n){
        if (b[i]<=a[0] || h<1) break;
        h -= b[i];
        ans++;
    }
    if (h>0) ans += (h / cnt) + (h%cnt!=0);

    cout << ans << endl;
    //printf("%.12f", ans);
}