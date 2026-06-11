#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector

int main(){
    int n,m;
    cin >> n >> m;
    ve<P> ab(n);
    rep(i,n){
        ll a,b;
        cin >> a >> b;
        ab[i] = P(a,b);
    }
    sort(ab.begin(), ab.end());
    int now = 0;
    ll ans = 0;
    int i = 0;
    while(now + ab[i].second < m){
        now += ab[i].second;
        ans += ab[i].first * ab[i].second;
        i++;
    }
    ans += ab[i].first * (ll)(m-now);
    cout << ans << endl;
    return 0;
}