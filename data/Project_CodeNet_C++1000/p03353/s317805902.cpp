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
ll k;
cin >> s >> k;
ll n = s.size();
map<string, ll> mp;
for (ll i = 0; i < n;i++){
    for (ll j=1; j <= min(n-i,k);j++){
        string tmp = s.substr(i, j);
        mp[tmp]++;
    }
}
string ans;
for (auto i : mp) {
    k--;
    if (k == 0) {
        ans = i.first;
        break;
    }
}
cout << ans << endl;
}