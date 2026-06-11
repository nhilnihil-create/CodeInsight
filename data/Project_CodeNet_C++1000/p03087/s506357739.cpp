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
    ll n, q; string s; cin >> n >> q >> s;
    vector<ll> ac(n,0);
    rep(i, n){
        if(i == 0) continue;
        ac[i] = ac[i-1];
        if(s[i] == 'C' && s[i-1] == 'A'){
            ac[i]++;
        }
    }
    //cout << s << endl;
    //for(auto i : ac) cout << i; cout << endl;
    rep(i, q){
        ll a, b; cin >> a >> b;
        cout << ac[b-1] - ac[a-1] << endl;
    }
    return 0;
}