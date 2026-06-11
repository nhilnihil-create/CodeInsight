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
ll t[n + 1], x[n + 1], y[n + 1];
t[0] = 0;
x[0] = 0;
y[0] = 0;
for (ll i = 0; i < n; i++) cin >> t[i+1] >> x[i+1] >> y[i+1];
bool flag = true;
for (ll i = 0; i < n; i++) {
    if (abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]) > t[i + 1] - t[i]) flag = false;
    if ((t[i + 1] - t[i]) % 2 != (abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i])) % 2) flag = false;
}
cout << (flag ? "Yes" : "No") << endl;
}