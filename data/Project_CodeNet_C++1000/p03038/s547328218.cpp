#include <bits/stdc++.h>
#define rep(i,n) for (long long int i = 0; i < (long long int)(n); i++)
using namespace std;
using ll = long long int;
using P = pair<ll,ll>;
const ll MOD = 1e9+7;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<P> v;
    rep(i,n) {
        ll a;
        cin >> a;
        v.push_back({a,1});
    }
    rep(i,m) {
        ll b, c;
        cin >> b >> c;
        v.push_back({c,b});
    }
    sort(v.begin(),v.end(),greater<>());
    ll ans = 0, cnt = 0;
    rep(i,n) {
        ans += v[cnt].first;
        v[cnt].second--;
        if (v[cnt].second == 0) cnt++;
    }
    cout << ans << endl;
    return 0;
}
