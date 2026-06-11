#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(ll itr=mp.begin();itr!=mp.end();itr -++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

int main(){
    ll a, b, q;
    cin >> a >> b >> q;

    vector<ll> s(a), t(b);
    rep(i, a)cin >> s[i];
    rep(i, b)cin >> t[i];
    
    sort(ALL(s));
    sort(ALL(t));

    rep(i, q){
        ll x;
        cin >> x;

        ll r_s, r_t, l_s, l_t;
        r_s = r_t = l_s = l_t = -1; 

        //神社の距離
        auto p_s = lower_bound(ALL(s), x);
        if(p_s != s.end()){
            r_s = *p_s - x;

            if(p_s - s.begin() > 0){
                l_s = x - s[p_s - s.begin() - 1];
            }
            else if(x == *p_s)l_s = 0;
        }
        else {
            l_s = x - s.back();
        }

        //寺の距離
        auto p_t = lower_bound(ALL(t), x);
        if(p_t != t.end()){
            r_t = *p_t - x;

            if(p_t - t.begin() > 0){
                l_t = x - t[p_t - t.begin() - 1];
            }
            else if(x == *p_t)l_t = 0;
        }
        else {
            l_t = x - t.back();
        }

        ll ans = LINF;
        //神社，寺共に東の方へ
        if(r_s > -1 && r_t > -1)ans = max(r_s, r_t);
        //神社は東，寺は西
        if(r_s > -1 && l_t > -1)ans = min(ans, r_s + l_t + min(r_s, l_t));
        //神社は西，寺は東
        if(l_s > -1 && r_t > -1)ans = min(ans, l_s + r_t + min(l_s, r_t));
        //神社，寺共に西へ
        if(l_s > -1 && l_t > -1)ans = min(ans, max(l_s, l_t));

        cout << ans << endl;
    }
}