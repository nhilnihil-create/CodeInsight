#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    map<ll,ll> mp;
    for(i = 1;i <= 100;++i){
        mp[i] = 0;
    }
    for(i = 2;i <= n;++i){
        j = i;
        ll tmp = 2;
        while(tmp <= 10){
            if(j%tmp == 0){
                ++mp[tmp];
                j /= tmp;
            }else{
                ++tmp;
            }
        }
        if(j != 1){
            ++mp[j];
        }
    }
    ll ans = 0;
    vector<ll> a; //75
    vector<ll> b; //25
    vector<ll> c; //15
    vector<ll> d; //5
    vector<ll> e; //3
    for(auto x: mp){
        ll tmp = x.second;
        ll tmp1 = x.first;
        if(tmp >= 74){
            a.push_back(tmp1);
            b.push_back(tmp1);
            c.push_back(tmp1);
            d.push_back(tmp1);
            e.push_back(tmp1);
        }else if(tmp >= 24){
            b.push_back(tmp1);
            c.push_back(tmp1);
            d.push_back(tmp1);
            e.push_back(tmp1);
        }else if(tmp >= 14){
            c.push_back(tmp1);
            d.push_back(tmp1);
            e.push_back(tmp1);
        }else if(tmp >= 4){
            d.push_back(tmp1);
            e.push_back(tmp1);
        }
        else if(tmp >= 2){
            e.push_back(tmp1);
        }
    }
    ans += a.size();
    //3x25
    for(i = 0;i < b.size();++i){
        rep(j, e.size()){
            if(b.at(i) != e.at(j)) ++ ans;
        }
    }
    //5x15
    for(i = 0;i < c.size();++i){
        rep(j, d.size()){
            if(c.at(i) != d.at(j)) ++ ans;
        }
    }
    //3x5x5
    ll k;
    for(i = 0;i < e.size();++i){
        for(j = 0;j < d.size()-1;++j){
            for(k = j+1;k < d.size();++k){
                if(e.at(i) != d.at(j) && e.at(i) != d.at(k)) ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}