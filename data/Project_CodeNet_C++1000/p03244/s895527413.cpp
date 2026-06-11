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

    vector<ll> odd(100010, 0), even(100010, 0);
    rep(i, n){
        ll a;
        cin >> a;
        if(i&1)odd[a]++;
        else even[a]++;
    }

    vector<ll> ord_1(100010), ord_2(100010);
    iota(ALL(ord_1), 0);
    iota(ALL(ord_2), 0);

    sort(ALL(ord_1), [&](ll x, ll y){
        return odd[x] > odd[y];
    });
    sort(ALL(ord_2), [&](ll x, ll y){
        return even[x] > even[y];
    });

    ll odd_cnt = n/2;
    ll even_cnt = n/2;
    if(n&1)even_cnt++;

    ll ans = n;
    if(ord_1[0] != ord_2[0]){
        ans = odd_cnt - odd[ord_1[0]] + even_cnt - even[ord_2[0]];
    }
    else {
        ans = odd_cnt - odd[ord_1[0]] + even_cnt - even[ord_2[1]];
        ans = min(ans, odd_cnt - odd[ord_1[1]] + even_cnt - even[ord_2[0]]);
    }

    cout << ans << endl;
}