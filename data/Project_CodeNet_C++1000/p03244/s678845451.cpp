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
    vector<ll> a(n, 0);
    map<ll, ll> odd;
    map<ll, ll> even;
    map<ll, ll> all;
    rep1(i, n){
        cin >> a[i];
        if (i & 1) odd[a[i]]++;
        else even[a[i]]++;
        all[a[i]]++;
    }
    if (all.size() == 1){
        cout << n/2 << endl;
        return 0;
    }
    vector<P> o, e;
    for (auto x: odd) o.push_back(make_pair(x.second, x.first));
    for (auto x: even) e.push_back(make_pair(x.second, x.first));
    sort(o.begin(), o.end(), greater<P>());
    sort(e.begin(), e.end(), greater<P>());
    ll ans;
    if (o[0].second!=e[0].second) ans = n - (o[0].first + e[0].first);
    else ans = n - max((o[0].first + e[1].first), (o[1].first + e[0].first));
    cout << ans << endl;
    //printf("%.12f", ans);
}