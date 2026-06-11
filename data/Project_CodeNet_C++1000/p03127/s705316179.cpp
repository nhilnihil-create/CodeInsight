#include<bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    if (a % b == 0) {
        return (b);
    } else {
        return (gcd(b, a % b));
    }
}

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

int main(){
    ll n, minn = 1e9+7, ans = 1e9+7; cin >> n;
    vector<ll> a(n); 
    rep(i,n){
        cin >> a[i];
        minn = min(a[i],minn);
    }

    
    for(auto x : a){
        if(x % minn != 0 && gcd(x,minn) == 1){
            put(1);
            return 0;
        }
    }

    ans = a[0];
    
    for(auto x : a){
        if(x == minn) continue;
        ans = min(ans, gcd(x, minn));
    }

    put(ans);
}