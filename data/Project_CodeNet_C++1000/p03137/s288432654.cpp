#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 100005

ll n , m , ans;
ll x[MAXX];

int main()
{
    _FastIO;
    cin >> n >> m;
    for(ll i = 0; i < m; i++){
        cin >> x[i];
    }
    sort(x , x + m);
    vector<ll> v;
    for(ll i = 1; i < m; i++){
        ans += (x[i] - x[i - 1]);
        v.push_back(x[i] - x[i - 1]);
    }
    sort(v.begin() , v.end());
    reverse(v.begin() , v.end());
    ll y = n - 1;
    if(y > (m - 1))
        y = m - 1;
    for(ll i = 0; i < y; i++){
        ans -= v[i];
    }
    cout << ans << endl;
    return 0;
}
