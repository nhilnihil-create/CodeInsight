#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    if (a%b == 0) return(b);
    else return(gcd(b, a%b));
}
 
ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}

int main() {
    ll n,m;
    string s,t;
    cin >> n >> m >> s >> t;
    ll x=gcd(n,m);
    n/=x,m/=x;
    bool ans=true;
    for(int i = 0; i < x; i++) {
        if(s[i*n] != t[i*m]) ans=false;
    }
    if(ans){
        cout << n*m*x << endl;
    }
    else{
        cout << -1 << endl;
    }

    return 0;
}