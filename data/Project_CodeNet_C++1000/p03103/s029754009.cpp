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
    ll n, m;
    cin >> n >> m;
    vector< vector<ll> > a(n, vector<ll>(2));
    rep1(i, n) cin >> a[i][0] >> a[i][1];
    ll ans = 0, num = 0, add = 0;
    sort(a.begin(), a.end());
    rep1(i, n){
        ans += a[i][0] * min(a[i][1], m-num);
        num += min(a[i][1], m-num);
        if (num == m) break;
    }
    cout << ans << endl;
}