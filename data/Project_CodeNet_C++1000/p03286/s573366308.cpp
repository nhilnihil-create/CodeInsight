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
    ll power = -2;
    vector<ll> ans;
    if(n==0){
        cout << 0 << endl;
        return 0;
    }
    while(abs(n)>0){
        ll t = n % 2;
        if (t < 0) t += 2;
        if (t == 0) ans.push_back(0);
        else
            ans.push_back(1);
        n -= t;
        n /= -2;
    }
    reverse(ans.begin(), ans.end());
    for (ll i=0;i<ans.size();i++){
        cout << ans[i];
    }
    cout << endl;
}