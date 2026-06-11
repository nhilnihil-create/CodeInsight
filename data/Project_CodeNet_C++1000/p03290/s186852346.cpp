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
    ll d, g;
    cin >> d >> g;

    vector<ll> p(d), c(d);
    rep(i, d)cin >> p[i] >> c[i];

    ll ans = INF;
    //bitが立っているものを全部使う
    rep(bit, (1<<d)){
        ll cnt = 0;
        ll point = g;
        rep(i, d)if((1<<i) & bit){
            cnt += p[i];
            point -= (i+1)*100*p[i] + c[i];
        }

        if(point <= 0){
            ans = min(ans, cnt);
            continue;
        }

        //使っていないものを大きい物を使う
        for(ll i = d-1; i >= 0; --i){
            if(!((1<<i) & bit)){
                ll c_i = point / ((i+1)*100);
                if(point % ((i+1)*100) > 0)c_i++;

                c_i = min(c_i, p[i]);
                point -= (i+1)*100*c_i;
                cnt += c_i;
                break;
            }
        }

        if(point <= 0)ans = min(ans, cnt);
    }

    cout << ans << endl;
}