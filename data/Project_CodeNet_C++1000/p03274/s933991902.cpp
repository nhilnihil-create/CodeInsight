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
    ll n, k;
    cin >> n >> k;

    vector<ll> minus, plus;
    plus.push_back(0);
    minus.push_back(0);
    rep(i, n){
        ll x;
        cin >> x;
        if(x < 0)minus.push_back(-1*x);
        else plus.push_back(x);
    }
    sort(ALL(minus));

    ll ans = INF;

    rep(i, plus.size()){
        if(i > k)break;
        if(minus.size() -1 + i < k)continue;

        ans = min(ans, plus[i] + 2*minus[k-i]);
        ans = min(ans, 2*plus[i] + minus[k-i]);
    }

    cout << ans << endl;
}