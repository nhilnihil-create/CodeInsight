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
    vector<ll> odd(1e5 + 1, 0);
    vector<ll> even(1e5 + 1, 0);
    for (ll i = 0; i < n;i++){
        ll t;
        cin >> t;
        if (i % 2 == 0) even[t]++;
        else
            odd[t]++;
    }
    ll oddmax = 0;
    ll oddmaxkey = 0;
    ll oddsecond = 0;
    ll oddsecondkey = 0;
    ll evenmax = 0;
    ll evenmaxkey = 0;
    ll evensecond = 0;
    ll evensecondkey = 0;
    ll ans = 0;
    for (ll i = 0; i < 1e5 + 1; i++) {
        if (chmax(oddmax, odd[i])) oddmaxkey = i;
        if (chmax(evenmax, even[i])) evenmaxkey = i;
    }
    for (ll i = 0; i < 1e5+1;i++){
        if (i == oddmaxkey) continue;
        else if(chmax(oddsecond,odd[i]))
            oddsecondkey = i;
    }
    for (ll i = 0; i < 1e5+1;i++){
        if (i == evenmaxkey) continue;
        else if(chmax(evensecond,even[i]))
            evensecondkey = i;
    }
    if (oddmaxkey != evenmaxkey) ans = n - oddmax - evenmax;
    else
        ans = min(n - oddmax - evensecond, n - oddsecond - evenmax);
    cout << ans << endl;
}