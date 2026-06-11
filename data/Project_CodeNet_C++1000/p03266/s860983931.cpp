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
ll n,k;
cin >> n >> k;
ll ans = 0;
if(k%2==1){
    ll tmp = n / k;
    ans = tmp * tmp * tmp;
} else {
    ll tmp = n / k;
    ll tmp2 = tmp;
    if (n % k >= k / 2) tmp2++;

    ans = tmp * tmp * tmp;
    ans += tmp2 * tmp2 * tmp2;
}
cout << ans << endl;

}