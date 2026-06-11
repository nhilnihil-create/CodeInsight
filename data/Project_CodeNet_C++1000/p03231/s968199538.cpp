#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

ll gcd(ll a, ll b){
    if(a < b) return gcd(b, a);
    ll r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

ll lcm(ll a, ll b){
    ll ret = a / gcd(a,b) * b;
    return ret;
}

bool is_prime(ll a){
    if(a == 1) return false;
    for(ll i=2; i*i<=a; i++){
        if(a%i == 0) return false;
    }
    return true;
}

int main(){
    ll n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    if(n < m){
        swap(n, m);
        swap(s, t);
    }
    ll l = lcm(n, m);
    map<ll, char> ans;
    rep(i, 0, n) ans[(l / n) * i] = s[i];
    rep(i, 0, m) {
        if(ans.count((l / m) * i) == 0) continue;
        if(ans[(l / m) * i] != t[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << l << endl;
    return 0;
}