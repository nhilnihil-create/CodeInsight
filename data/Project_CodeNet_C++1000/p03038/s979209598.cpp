#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;


int main() {
    ll n, m; cin >> n >> m;
    V<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    V<P<ll, ll> > pa(m);
    for(int i = 0; i < m; i++){
        ll b, c; cin >> b >> c;
        pa[i] = make_pair(c, b);
    }

    sort(ALL(a));
    sort(ALL(pa), greater<P<ll, ll>>());

    int p = 0;
    for(int i = 0; i < m; i++){
        if(n < p) break;
        ll b = pa[i].second;
        ll c = pa[i].first;
        if(a[p] <= c){
            for(int j = p; j < min(p + b, n); j++){
                if(a[j] <= c) a[j] = c;
            }
            p += b;
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += a[i];
    }
    cout << ans << endl;
}
