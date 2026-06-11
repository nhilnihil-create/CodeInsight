#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

ll gcd(ll a, ll b){
    if(b == 0) return a;
    if(a < b){
        ll tmp = b;
        b = a;
        a = tmp;
    }

    while(b != 0){
        ll tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}

int main(){
    ll n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    ll l = n/gcd(n, m)*m, ln = l/n, lm = l/m;
    ll p = 0, q = 0, sp = 0, st = 0;
    for(ll i = 0; i < l; i += min(ln, lm)){
        if(st == sp && i == st){
            if(s[p] != t[q]){
                cout << "-1" << endl;
                return 0;
            }
        }
        if(i >= sp) sp = ++p*ln;
        if(i >= st) st = ++q*lm;
    }    
    cout << l << endl;
    return 0;
}