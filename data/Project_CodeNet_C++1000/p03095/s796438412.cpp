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
map<char, ll> mp;
for (ll i = 0; i < n; i++) mp[s[i]]++;
ll ans = 1;
for (auto i : mp) {
    ans *= (i.second+1);
    ans %= MOD;
}
cout << ans-1 << endl;
}