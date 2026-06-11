#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 100005

ll n , m;
ll a[MAXX];
ll b[MAXX];

int main()
{
    _FastIO;
    cin >> n >> m;
    vector<pair<ll , ll> > v;
    for(ll i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        v.push_back({a[i] , b[i]});
    }
    sort(v.begin() , v.end());
    ll s = m;
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ll x = v[i].first;
        ll y = v[i].second;
        if(s >= y){
            ans += x * y;
            s -= y;
        }
        else{
            ans += x * s;
            s = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
