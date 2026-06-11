#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    rep(ti,t){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if(d < b){
            cout << "No" << endl;
            continue;
        }
        if(a < b){
            cout << "No" << endl;
            continue;
        }
        ++c;
        if(c >= b){
            cout << "Yes" << endl;
            continue;
        }
        a %= b;
        d %= b;
        ll g = gcd(d, b);
        a += (b - a - 1) / g * g;
        if(a < b && c <= a) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}
