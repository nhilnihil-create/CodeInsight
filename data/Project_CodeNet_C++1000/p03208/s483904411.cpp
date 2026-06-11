#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <bitset>
using namespace std;
using ll = long long;
constexpr ll INF = 1010000000000000017LL;
constexpr ll mod = 1000000007;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define vsort(v) sort(all(v))

ll powmod(ll x, ll y);

int main() {
    int k,n;cin>>n>>k;
    vector<ll> h(n);
    rep(i,n) cin>>h[i];
    vsort(h);
    // rep(i,n) cout<<h[i]<<' ';
    // cout<<endl;
    ll ans=(1e+10);
    for (size_t i = 0; i < n-k+1; i++)
    {
        ans = min(ans, h.at(i+k-1)-h.at(i));
        // cout<<h[i+k-1]<<' '<<h[i]<<' '<<ans<<endl;
    }
    cout<<ans<<endl;
    
}

/************************************/
ll powmod(ll x, ll y){
    ll res=1;
    rep(i,y) res=res*x%mod;
    return res;
}

