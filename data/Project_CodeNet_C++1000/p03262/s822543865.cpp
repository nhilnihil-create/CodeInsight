#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if(a%b==0){return b;}
    else{return gcd(b, a%b);}
}

int main(){
    int n; ll s; cin >> n >> s;
    vector<ll> x(n);
    for(int i=0; i<n; ++i){cin >> x[i];}
    vector<ll> d(n);
    for(int i=0; i<n; ++i){d[i] = abs(s-x[i]);}
    ll res = d[0];
    for(int i=1; i<n; ++i){
        ll di = d[i];
        res = gcd(di, res);
    }
    cout << res << endl;
    return 0;
}