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
void divisor(ll n,map<ll,ll>&mp){
    for(long long i = 1; i * i <= n; i++) {
        if(n%i==0){
            mp[i]++;
            if (!(i * i == n)) mp[n / i]++;
        }
    }
    return;
}
int main(){
    ll n;
    cin >> n;
    map<ll, ll> mp;
    divisor(n,mp);
    ll ans = 0;
    for (auto i:mp){
        if (i.first == 1) continue;
        ll t = i.first;
        t--;
        if (n / t == n % t) ans += t;
    }
    cout << ans << endl;
}