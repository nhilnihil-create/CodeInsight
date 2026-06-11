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
    ll n,m;
    cin >> n;
    map<ll, ll> candidate, needs;
    for (ll i = 0; i < n;i++){
        ll d;
        cin >> d;
        candidate[d]++;
    }
    cin >> m;
    for (ll i = 0; i < m;i++){
        ll t;
        cin >> t;
        needs[t]++;
    }
    bool flag = true;
    for(auto i:needs){
        if (i.second > candidate[i.first]) flag = false;
    }
    cout << (flag ? "YES" : "NO") << endl;
}