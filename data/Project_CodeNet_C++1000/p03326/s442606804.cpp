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

    vector<vector<ll>> score(8, vector<ll>(n));
    rep(i, n){
        ll x, y, z;
        cin >> x >> y >> z;

        //３つのプラマイを優先に
        rep(j, 8){
            ll v = 0;
            
            //ビットが立っていると正が嬉しい
            if(j & 1)v += x;
            else v -= x;

            if(j & 2)v += y;
            else v -= y;

            if(j & 4)v += z;
            else v -= z;
            
            score[j][i] = v;
        }
    }

    ll ans = 0;
    rep(i, 8){
        sort(ALL(score[i]), greater<ll>());
        ll res = 0;
        rep(j, m)res += score[i][j];
        ans = max(ans, res);
    }
    cout << ans << endl;
}