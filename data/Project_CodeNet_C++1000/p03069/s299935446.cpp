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
    ll n; string s; cin >> n >> s;
    ll ans = 200005;
    bool z = false;
    vector<ll> bl(n,0), wh(n,0);
    if(s[0] == '#') bl[0] = 1; else wh[0] = 1;
    for(ll i = 1; i < n; ++i){
        if(s[i] == '#') bl[i] = bl[i-1] + 1, wh[i] = wh[i-1];
        else wh[i] = wh[i-1] + 1, bl[i] = bl[i-1];
    }
    if(wh[n-1] == n || bl[n-1] == n){
        cout << 0 << endl;
        return 0;
    }
    //rep(i, n) cout << bl[i] << " ";
    //cout << endl;
    //rep(i, n) cout << wh[i] << " ";
    //cout << endl;
    rep(i,n){
        ll tmp = 0;
        if(s[i] == '#'){
            tmp += wh[n-1] - wh[i];
            if(i > 0) tmp += bl[i-1];
            ans = min(ans, tmp);
        }else{
            tmp += wh[n-1] - wh[i];
            tmp += bl[i];
            ans = min(ans, tmp);
        }
        //cout << tmp << " ";
    }
    //cout << endl;
    cout << ans << endl;
    return 0;
}
