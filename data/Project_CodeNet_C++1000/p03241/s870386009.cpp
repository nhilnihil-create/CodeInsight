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
vector<long long> divisor(long long n){
    vector<long long> res;
    for(long long i = 1; i * i <= n; i++) {
        if(n%i==0){
            res.push_back(i);
            if (!(i * i == n)) res.push_back(n / i);
        }
    }
    return res;
}
int main(){
ll n,m;
cin >> n >> m;
vector<ll> mp = divisor(m);
ll ans = 0;
for (auto i : mp) {
    if (i <= m / n) chmax(ans, i);
}
cout << ans << endl;
}