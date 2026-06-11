#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
using ll = long long;

int main()
{
    ll i,j;
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n);
    unordered_map <ll,ll> mp;
    for(i = 0;i < n;++i){
        cin >> a.at(i);
    }
    vector<ll> b(n+1,0);
    for(i = 0;i < n;++i){
        b.at(i+1) = a.at(i) + b.at(i);
        b.at(i+1) %= m;
        ll tmp = b.at(i+1);
        if(mp.count(tmp)){
            ++mp[tmp];
        }else{
            mp[tmp] = 1;
        }
    }
    if(mp.count(0)){
        ++mp[0];
    }else{
        mp[0] = 1;
    }
    ll ans = 0;
    for(auto x: mp){
        ll tmp = x.second;
        ans += tmp*(tmp-1)/2;
    }
    cout << ans << endl;

    return 0;
}