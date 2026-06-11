#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll bit[70];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    rep(i,n){
        ll a;
        cin >> a;
        rep(j,61){
            if(a>>j & 1) ++bit[j];
        }
    }
    ll ans = 0, two = 1;
    rep(j,60) two *= 2LL;
    for(int j = 60; j >= 0; --j){
        if(k < two){
            ans += two * bit[j];
            two /= 2;
            continue;
        }
        if(bit[j] <= n - bit[j]){
            ans += two * (n - bit[j]);
            k -= two;
        }
        else{
            ans += two * bit[j];
        }
        two /= 2;
    }
    cout << ans << endl;
    return 0;
}