#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    ll g = gcd(a, b);
    return a / g * b;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    ll l = lcm(n, m);
    ll p = l/n, q = l/m;
    map<ll, char> cnt;
    map<ll, bool> used;
    rep(i,n){
        cnt[i*p] = s[i];
        used[i*p] = true;
    }
    rep(i,m){
        if(used[i*q] && (cnt[i*q] != t[i])){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << l << endl;
    return 0;
}
