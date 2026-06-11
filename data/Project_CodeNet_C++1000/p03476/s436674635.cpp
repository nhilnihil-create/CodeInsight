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

    const ll nmax = 100001;
    vector<bool> prime(nmax, true);
    prime[0] = prime[1] = false;
    for(ll x = 2; x < nmax; x++){
        if(prime[x]) for(ll y = x*2; y < nmax; y += x) prime[y] = false;
    }
    
    vector<ll> like(nmax, 0);
    for(ll x = 3; x < nmax; x+=2){
        if(prime[x] && prime[(x+1)/2]) like[x] = like[x-2]+1;
        else like[x] = like[x-2];
    }

    rep(i, n){
        ll l, r; cin >> l >> r;
        ll cnt = 0;
        bool lp = prime[l] && prime[(l+1)/2], rp = prime[r] && prime[(r+1)/2];
        if(lp && rp) cnt = like[r] - like[l] + 1;
        else if(!lp && rp) cnt = like[r] - like[l];
        else if(lp && !rp) cnt = like[r] - like[l] + 1;
        else cnt = like[r] - like[l];
        
        cout << cnt << endl;
    }
    return 0;
}