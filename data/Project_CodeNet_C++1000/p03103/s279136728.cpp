#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main(){
    Hello
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> v;
    for(int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        v.push_back({a, -b});
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for(int i = 0; i < v.size(); i++){
        ans += v[i].first * (min(m, -1 * v[i].second));
        m -= min(m, -1 * v[i].second);
    }
    cout << ans;
    return 0;
}