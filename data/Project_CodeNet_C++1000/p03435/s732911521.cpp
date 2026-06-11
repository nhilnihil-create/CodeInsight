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
    ll c[3][3];
    for (ll i = 0; i < 3;i++){
        for (ll j = 0; j < 3;j++){
            cin >> c[i][j];
        }
    }
    bool flag = true;
        ll a[3], b[3];
        a[0] = 0;
        a[1] = c[1][0] - c[0][0];
        a[2] = c[2][0] - c[0][0];
        b[0] = c[0][0];
        b[1] = c[0][1];
        b[2] = c[0][2];
        for (ll i = 0; i < 3;i++){
            for (ll j = 0; j < 3;j++){
                if (c[i][j] != (a[i] + b[j])) flag = false;
            }
        }
    cout << (flag ? "Yes" : "No") << endl;
}