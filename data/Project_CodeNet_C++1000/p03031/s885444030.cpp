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

    vector<ll> s(m, 0);
    rep(i, m){
        ll k;
        cin >> k;

         rep(j, k){
             ll s_i;
             cin >> s_i;
             s_i--;
             s[i] += (1<<s_i);
         }
    }

    ll p = 0;
    rep(i, m){
        ll p_i;
        cin >> p_i;
        p += (1<<i)*p_i;
    }

    ll ans = 0;
    rep(i, (1<<n)){
        ll res = 0;

        rep(j, m){
            ll and_s = (i & s[j]);
            
            ll cnt = 0;
            rep(k, n){
                if((1<<k)&and_s)cnt++;
            }

            res += (1<<j) * (cnt%2);
        }

        if(res == p)ans++;
    }

    cout << ans << endl;
}