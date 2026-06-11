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
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    rep1(i, n) cin >> a[i];
    rep1(i, n) cin >> b[i];
    rep1(i, n) cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    ll ans = 0;
    rep1(i, n){
        ll cnt = 1;
        ll left = -1;
        ll right = n;
        while (right-left>1){
            ll mid = (left+right) / 2;
            if (a[mid]<b[i]) left = mid;
            else right = mid;
        }
        cnt *= right;
        left = -1;
        right = n;
        while (right-left>1){
            ll mid = (left+right) / 2;
            if (c[mid]<=b[i]) left = mid;
            else right = mid;
        }
        cnt *= n - right;
        ans += cnt;
    }
    cout << ans << endl;
    //printf("%.12f", ans);
}