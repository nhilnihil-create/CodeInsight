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
    vector<ll> c(n), s(n), f(n);
    rep(i, n-1) cin >> c[i] >> s[i] >> f[i];
    c[n-1] = s[n-1] = f[n-1] = 0;
    rep(i, n){
        ll time = s[i] + c[i];
        for(ll j = i+1; j < n-1; ++j){
            ll next = 0;
            if(time >= s[j]){
                ll t = (time - s[j])%f[j];
                if(t > 0) time += f[j] - t;
            }else time = s[j];
            time += c[j];
        }
        cout << time << endl;
    }
    return 0;
}