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
    vector<map<ll,ll>> nn(n+1);
    vector<pair<ll, ll>> year(m);
    rep(i, m){
        ll p, y; cin >> p >> y;
        year[i].first = y;
        year[i].second = p;
        nn[p].emplace(y, y);
    }
    for(ll i = 1; i < n+1; ++i){
        ll inx = 1;
        for(auto j = nn[i].begin(); j != nn[i].end(); ++j){
            (*j).second = inx;
            inx++;
        }
    }
    rep(i, m){
        ll y = year[i].first, p = year[i].second;
        printf("%06lld%06lld\n", p, nn[p][y]);
    }
    return 0;
}