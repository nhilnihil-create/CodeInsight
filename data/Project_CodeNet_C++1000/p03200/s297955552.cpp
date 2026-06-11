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
    string s;
    cin >> s;
    ll n = s.size();
    ll cnt = 0;
    ll ans = 0;
    for (ll i = 0; i < n;i++){
        if (s[i] == 'B') cnt++;
        else
            ans += cnt;
    }
    cout << ans << endl;
}