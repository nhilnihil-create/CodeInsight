#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<ll , ll>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 100005

ll n , m;
ll a[MAXX];
ll b[MAXX];
ll c[MAXX];

int main()
{
    _FastIO;
    cin >> n >> m;
    multiset<ll> ms;
    multiset<ll>::iterator it;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        ms.insert(a[i]);
    }
    vector<pair<ll , ll> > v;
    for(ll i = 0; i < m; i++){
        cin >> b[i] >> c[i];
        v.push_back({c[i] , b[i]});
    }
    sort(v.begin() , v.end());
    ll p = v.size();
    p--;
    while((*(ms.begin())) < (v[p].first) && p != -1){
        ll h = v[p].second;
        ll y = 0;
        ll f = v[p].first;
        while((*(ms.begin())) < f && y < h){
            it = ms.begin();
            ll k = *it;
            ms.erase(it);
            ms.insert(f);
            y++;
        }
        p--;
    }
    ll ans = 0;
    for(it = ms.begin(); it != ms.end(); it++){
        ans += (*it);
    }
    cout << ans << endl;
    return 0;
}
