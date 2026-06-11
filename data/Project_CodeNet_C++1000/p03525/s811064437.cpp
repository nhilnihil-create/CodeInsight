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
    ll n;
    cin >> n;
    vector<ll> d(n+1,0);
    for(i = 1;i <= n;++i){
        cin >> d.at(i);
    }
    sort(all(d));
    vector<ll> tmp;
    for(i = 0;i <= n;++i){
        if(i%2){
            tmp.push_back(d.at(i));
        }else{
            tmp.push_back((24-d.at(i))%24);
        }
    }
    sort(all(tmp));
    ll ans = 1e9;
    for(i = 0;i < n;++i){
        ll t = tmp.at(i+1) - tmp.at(i);
        ans = min(ans, t);
    }
    cout << ans << endl;
    return 0;
}