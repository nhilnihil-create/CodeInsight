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
ll n;
string s;
cin >> n >> s;
ll ans = 0;
for (ll i = 0; i < n; i++) {
    map<char, bool> a;
    map<char, bool> b;
    ll tmp = 0;
    for (ll j = 0; j < i; j++) {
        a[s[j]] = true;
    }
    for (ll j = i; j < n;j++){
        b[s[j]] = true;
    }
    for (ll i = 0; i < 26;i++){
        char t = 'a' + i;
        if (a[t] && b[t]) tmp++;
    }
    chmax(ans, tmp);
}
cout << ans << endl;
}