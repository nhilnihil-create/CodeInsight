#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

template<typename T>
istream& operator>> (istream& is, vector<T> &vec){
    for(T& x: vec) is >> x;
    return is;
}

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    map<ll, ll, greater<ll>> list;
    rep(i, n){
        cin >> a[i];
        list[a[i]]++;
    }
    rep(i, m){
        ll b, c; cin >> b >> c;
        list[c] += b;
    }
    ll ans = 0, cnt = 0;
    for(auto i : list){
        ans += i.first * i.second;
        cnt += i.second;
        if(cnt > n){
            ans -= i.first * (cnt - n);
            break;
        }
    }
    cout << ans << endl;
    return 0;
}