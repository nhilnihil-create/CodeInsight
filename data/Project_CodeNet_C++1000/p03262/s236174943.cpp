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
    ll n, X; cin >> n >> X;
    vector<ll> x(n), l(n); rep(i,n) cin >> x[i];

    ll minn = 1e10, ans = 1e10;

    x.push_back(X);

    sort(x.begin(), x.end());
    
    for(long long i = 0; i < n; i++){
        l[i] = x[i+1] - x[i];
        minn = min(minn, x[i+1] - x[i]);
    }

    for(long long i = 0; i < n; i++){
        ans = min(ans,gcd(l[i], minn));
    }

    put(ans);
}