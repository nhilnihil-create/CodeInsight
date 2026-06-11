#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    vector<ll> cnt(61, 0);
    rep(i,n){
        ll a;
        cin >> a;
        rep(j,61){
            if(a>>j & 1) ++cnt[j];
        }
    }
    ll ans = 0;
    for(int i = 60; i >= 0; --i){
        ll two = 1LL;
        rep(j,i) two *= 2;
        if(k >= two){
            if(n - cnt[i] >= cnt[i]){
                k -= two;
                ans += (n - cnt[i]) * two;
                continue;
            }
        }
        ans += cnt[i] * two;
    }
    cout << ans << endl;
    return 0;
}
