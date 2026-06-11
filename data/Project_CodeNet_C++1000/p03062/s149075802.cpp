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
    ll minus = 0;
    rep(i, n){
        cin >> a[i];
        b[i] = abs(a[i]);
        if(a[i] < 0) minus++;
        if(a[i] == 0) minus = 0;
    }
    sort(b.begin(), b.end());
    ll sum = 0;
    rep(i, n) sum += abs(a[i]);
    if(minus%2) sum -= 2 * b[0];
    cout << sum << endl;
    return 0;
}