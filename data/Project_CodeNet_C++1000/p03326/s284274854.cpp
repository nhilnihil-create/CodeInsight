#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n,m;
    cin >> n >> m;
    vector<ll> x(n);
    vector<ll> y(n);
    vector<ll> z(n);
    for(i = 0;i < n;++i){
        cin >> x.at(i) >> y.at(i) >> z.at(i);
    }
    ll ans = 0;
    for(i = 0;i < 8;++i){
        ll tans = 0;
        vector<ll> tx = x;
        vector<ll> ty = y;
        vector<ll> tz = z;
        if(i & 1){
            rep(j,n){
                tx.at(j) *= -1;
            }
        }
        if(i & 2){
            rep(j,n){
                ty.at(j) *= -1;
            }
        }
        if(i & 4){
            rep(j,n){
                tz.at(j) *= -1;
            }
        }
        vector<ll> tv;
        rep(j,n){
            ll tmp = tx.at(j) + ty.at(j) + tz.at(j);
            tv.push_back(tmp);
        }
        sort(all(tv));
        for(j = 0;j < m;++j){
            tans += tv.at(n-1-j);
        }
        ans = max(ans, tans);
    }
    cout << ans << endl;
    return 0;
}