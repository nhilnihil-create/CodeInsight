#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> mp;
    rep(i,n){
        cin >> a[i];
        ++mp[a[i]];
    }
    int ans = 0;
    for(int i = 30; i >= 1; --i){
        ll x = (1LL << i);
        for(auto &p : mp){
            if(p.first >= x) continue;
            if(p.second == 0) continue;
            ll y = x - p.first;
            if(y > p.first) continue;
            if(y == p.first){
                ans += p.second / 2;
                p.second %= 2;
            }
            else{
                ll cnt = min(p.second, mp[y]);
                ans += cnt;
                p.second -= cnt;
                mp[y] -= cnt;
            }
        }
    }
    cout << ans << endl;
    return 0;
}