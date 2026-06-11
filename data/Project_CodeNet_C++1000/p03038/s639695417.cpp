#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

int main(){
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    rep(i, n)cin >> a[i];
    sort(ALL(a));

    vector<ll> b(m), c(m);
    rep(i, m)cin >> b[i] >> c[i];

    vector<ll> ord(m);
    iota(ALL(ord), 0);
    sort(ALL(ord), [&](ll x, ll y){
        return c[x] > c[y];
    });

    ll back = 0;
    rep(i, m){
        if(back >= n)break;
        ll p = ord[i];

        rep(j, b[p]){
            if(a[back] >= c[p])back = n;
            if(back >= n)break;

            a[back] = c[p];

            back++;
        }
    }

    ll ans = 0;
    rep(i, n)ans+=a[i];
    cout << ans << endl;
}