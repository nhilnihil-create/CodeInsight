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
    ll n;
    cin >> n;

    vector<ll> x(n), y(n), h(n);
    rep(i, n){
        cin >> x[i] >> y[i] >> h[i];
    } 
    vector<ll> ord(n);
    iota(ALL(ord), 0);
    sort(ALL(ord), [&](ll a, ll b){
        return h[a] > h[b];
    });

    if(h[ord[0]] == 0){
        ll ans = INF;
        rep(i, n){
            ans = min(ans, x[i] + y[i]);
        }

        cout << "0 0 " << ans << endl;
        return 0;
    }

    rep(cx, 101)rep(cy, 101){
        ll res = abs(x[ord[0]] - cx) + abs(y[ord[0]] - cy) + h[ord[0]]; 
        bool isok = true;
        rep(i, n){
            ll high = abs(x[i] - cx) + abs(y[i] - cy) + h[i]; 

            if(high == res)continue;
            else if(h[i] == 0 && high > res)continue;

            isok = false;
            break;   
        }

        if(isok){
            cout << cx << " " << cy << " " << res << endl;
            return 0;
        }
    }
}