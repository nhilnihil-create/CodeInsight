// Header {{{
#include <bits/stdc++.h>

using namespace std;
template<typename T>
using reversed_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T> >;
typedef unsigned long long int ull;
typedef long long int ll;
#define rep(i,a,b) for (ll i=(a); i<(b); i++)
typedef pair<ll,ll> PLL;
// }}}

const ll INF=1e10;
ll W,H,N;
// ll debug[100][100];
vector<ll> v(200010, INF); // x -> most left size block

signed main() {
    cin>>H>>W>>N;
    rep(i,0,N){
        ll x,y;
        cin>>x>>y;
        x--; y--;
        // debug[x][y]=1;
        v[x] = min(v[x], y);
    }

    // rep(x,0,H){
    //     rep(y,0,W){
    //         cout<<(debug[x][y]==1 ? '#' : '.');
    //     }
    //     cout<<endl;
    // }

    ll ans = 1;
    ll r = 0; // right boundary
    for (ll x = 1; x < H; x++){
        if (r >= v[x]){
            break;
        }
        ans++;
        if (r+1 < v[x]){
            r = r+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
