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
    vector<ll> b(n);
    for (ll i = 0; i < n; i++) cin >> b[i];
    stack<ll> ans;
    for (ll t = 0; t < n;t++) {
        ll k = b.size();
        for (ll i = k - 1; i >= 0; i--) {
            if (b[i] == i+1) {
                ans.push(b[i]);
                b.erase(b.begin() + i);
                break;
            }
        }
    }
    if(ans.size()!=n){
        cout << -1 << endl;
    }
    else{
        while(!ans.empty()){
            cout << ans.top() << endl;
            ans.pop();
        }
    }
}