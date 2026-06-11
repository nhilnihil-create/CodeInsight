#include <bits/stdc++.h>

#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9+7;
const ll LINF = 1LL << 60;
const int INF = 1e9 + 7;

bool CompareX_smaller(pll a, pll b){
    if(a.first == b.first)return a.second < b.second;
    else return a.first < b.first;
}

int main(){
    ll n;
    cin >> n;

    vector<pll> red(n), blue(n);
    rep(i, n)cin >> red[i].first >> red[i].second;
    rep(i, n)cin >> blue[i].first >> blue[i].second;

    sort(ALL(blue), CompareX_smaller);

    ll ans = 0;
    bool used[1000] = {};
    rep(i, n){
        ll max_y_pos = -1;
        ll max_y = -1;
        rep(j, n)if(!used[j]){
            if(blue[i].first > red[j].first && blue[i].second > red[j].second){
                if(red[j].second >= max_y){
                    max_y = red[j].second;
                    max_y_pos = j;
                }
            }
        }

        if(max_y_pos >= 0){
            ans++;
            used[max_y_pos] = true;
        }
    }

    cout << ans << endl;

}