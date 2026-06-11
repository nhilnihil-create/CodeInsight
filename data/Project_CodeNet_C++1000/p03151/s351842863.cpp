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
    ll n; cin >> n;
    vector<ll> a(n), b(n);
    ll as = 0, bs = 0;
    rep(i, n){
        cin >> a[i];
        as += a[i];
    }
    rep(i, n){
        cin >> b[i];
        bs += b[i];
    }
    if(as < bs){
        cout << -1 << endl;
        return 0;
    }
    vector<pair<ll, ll>> c;
    ll cs = 0, ds = 0, cnt = 0;
    rep(i, n){
        if(a[i] < b[i]) cs += a[i], ds += b[i], cnt++;
        else c.emplace_back(a[i]-b[i], a[i]);
    }
    if(cnt == 0){
        cout << cnt << endl;
        return 0;
    }
    sort(c.rbegin(), c.rend());
    rep(i, c.size()){
        cs += c[i].second, ds += c[i].second - c[i].first;
        if(cs >= ds){
            cout << cnt + i + 1 << endl;
            break;
        }
    }
    return 0;
}