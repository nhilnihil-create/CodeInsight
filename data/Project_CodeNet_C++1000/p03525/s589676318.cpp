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
    map<ll,ll> mp;
    for(i = 0;i <= 12;++i){
        mp[i] = 0;
    }
    ++mp[0];
    for(i = 0;i < n;++i){
        ll d;
        cin >> d;
        ++mp[d];
    }
    ll ans = 0;
    for(ll bit = 0;bit < (1 << 13);++bit){
        set<ll> se;
        for(i = 0;i < 13;++i){
            if(bit & (1 << i)) se.insert(i);
        }
        vector<ll> tmp;
        for(i = 0;i < 13;++i){
            if(mp[i] > 2){
                cout << 0 << endl;
                return 0;
            }else if(mp[i] == 2){
                tmp.push_back(i);
                tmp.push_back((24-i)%24);
            }else if(mp[i] == 1){
                if(se.count(i)){
                    tmp.push_back(i);
                }else{
                    tmp.push_back((24-i)%24);
                }
            }
        }
        sort(all(tmp));
        ll tans = 1e9;
        for(i = 0;i < tmp.size()-1;++i){
            ll t = tmp.at(i+1) -  tmp.at(i);
            tans = min(tans, t);
        }
        tans = min(tans, 24-tmp.back());
        ans = max(ans, tans);
    }
    cout << ans << endl;
    return 0;
}