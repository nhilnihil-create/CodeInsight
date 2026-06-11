#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n,m;
    cin >> n >> m;
    vector<pair<ll, ll>> b(n);
    rep (i, n) {
        cin >> b[i].first >> b[i].second;
    }
    sort(ALL(b));
    ll ans=0;
    rep (i, n) {
        if (m > b[i].second) {
            m -= b[i].second;
            ans += b[i].first * b[i].second;
        }else{
            ans += m * b[i].first;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}