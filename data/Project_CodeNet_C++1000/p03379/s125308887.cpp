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
vector<ll> x(n);
for (ll i = 0; i < n; i++) cin >> x[i];
vector<ll> y = x;
sort(y.begin(),y.end());
ll mid1 = n / 2 - 1;
ll mid2 = n / 2;
for (ll i = 0; i < n;i++){
    if (x[i] <= y[mid1])
        cout << y[mid2] << endl;
    else if (x[i] >= y[mid2])
        cout << y[mid1] << endl;
}
}