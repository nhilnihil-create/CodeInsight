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
    
    vector<ll> a(m),  b(m);
    rep(i, m)cin >> a[i] >> b[i];

    vector<ll> ord(m);
    iota(ALL(ord), 0);

    sort(ALL(ord), [&](ll x, ll y){
        return b[x] < b[y];
    });

    ll ans = 0;
    ll back = -1;
    rep(i, m){
        if(a[ord[i]] < back)continue;
        
        ans++;
        back = b[ord[i]];
    }

    cout << ans << endl;
}
