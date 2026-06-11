#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int know_digit(ll n)
{
    int ans = 0;
    while(n){
        n /= 10;
        ++ans;
    }
    return ans;
}

int main()
{
    ll i,j;
    ll n,m;
    cin >> n >> m;
    vector<ll> p(m);
    vector<ll> y(m);
    vector<vector<ll>> city(n);
    for(i = 0;i < m;++i){
        cin >> p.at(i) >> y.at(i);
        --p.at(i);
        city.at(p.at(i)).push_back(y.at(i));
    }
    for(i = 0;i < n;++i){
        sort(all(city.at(i)));
    }
    for(i = 0;i < m;++i){
        ll num = lower_bound(all(city.at(p.at(i))), y.at(i)) - city.at(p.at(i)).begin();
        ll digit = know_digit(p.at(i)+1);
        rep(j, 6 - digit) cout << 0;
        cout << p.at(i)+1;
        digit = know_digit(num+1);
        rep(j, 6 - digit) cout << 0;
        cout << num+1 << endl;
    }

    return 0;
}