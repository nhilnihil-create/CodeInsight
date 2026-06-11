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
cin >> n;
map<char, ll> mp;
for (ll i = 0; i < n;i++){
    string s;
    cin >> s;
    mp[s[0]]++;
}
ll ans = 0;
ans += mp['M'] * mp['A'] * mp['R'];
ans += mp['M'] * mp['A'] * mp['C'];
ans += mp['M'] * mp['A'] * mp['H'];
ans += mp['M'] * mp['R'] * mp['C'];
ans += mp['M'] * mp['R'] * mp['H'];
ans += mp['M'] * mp['C'] * mp['H'];
ans += mp['A'] * mp['R'] * mp['C'];
ans += mp['A'] * mp['R'] * mp['H'];
ans += mp['A'] * mp['C'] * mp['H'];
ans += mp['R'] * mp['C'] * mp['H'];
cout << ans << endl;
}