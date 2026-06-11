#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll x,y,z,k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x);
    vector<ll> b(y);
    vector<ll> c(z);
    for(i = 0;i < x;++i){
        cin >> a.at(i);
    }
    for(i = 0;i < y;++i){
        cin >> b.at(i);
    }
    for(i = 0;i < z;++i){
        cin >> c.at(i);
    }
    vector<ll> ab;
    for(i = 0;i < x;++i){
        rep(j,y){
            ab.push_back(a.at(i) + b.at(j));
        }
    }
    sort(all(ab), greater<ll>());
    vector<ll> abc;
    for(i = 0;i < min(k,x*y);++i){
        rep(j,z){
            abc.push_back(ab.at(i) + c.at(j));
        }
    }
    sort(all(abc), greater<ll>());
    for(i = 0;i < k;++i){
        cout << abc.at(i) << endl;
    }

    return 0;
}