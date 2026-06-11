#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
constexpr long double EPS = 1e-11;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main(){
    ll n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    for (ll i = 0; i < gcd(n, m);i++) {
        if(s[n*i/gcd(n,m)]!=t[m*i/gcd(n,m)]){
            cout << "-1" << endl;
            return 0;
        }
    }
    cout << lcm(n, m) << endl;
}