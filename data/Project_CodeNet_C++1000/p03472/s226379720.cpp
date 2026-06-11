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
    ll n, h; cin >> n >> h;
    vector<ll> a(n), b(n);
    rep(i, n){
        ll aa, bb; cin >> aa >> bb;
        a[i] = aa; b[i] = bb;
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    ll cnt = 0, remain = h;
    //cout << endl;
    rep(i, n){
        if(b[i] < a[0]) break;
        if(remain <= 0) break;
        remain -= b[i];
        cnt++;
        //cout << b[i] << endl;
    }
    if(remain > 0){
        cnt += remain / a[0];
        if(remain%a[0] != 0) cnt++;
        //printf("###\n%lld %lld %lld\n", a[0], remain / a[0], remain % a[0]);
    }
    cout << cnt << endl;
    return 0;
}