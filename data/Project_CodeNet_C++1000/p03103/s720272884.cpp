#include "bits/stdc++.h"
#include <random>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    vector<P> v(n);
    rep(i,n) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    ll ans = 0;
    rep(i,n){
        if(m <= v[i].second){
            ans += v[i].first * m;
            break;
        }
        ans += v[i].first * v[i].second;
        m -= v[i].second;
    }
    cout << ans << endl;
    return 0;
}
