//https://atcoder.jp/contests/agc026/submissions/2848703
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

bool solve(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if(d < b) return false;
    if(a < b) return false;
    ++c;
    if(c >= b) return true;
    d %= b;
    ll g = gcd(d, b);
    a %= b;
    a += (b - a - 1) / g * g;
    if(c <= a && a < b) return false;
    return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    rep(_,t){
        cout << (solve() ? "Yes" : "No") << endl;
    }
    return 0;
}
