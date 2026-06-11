#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

long double n, m, d;

int main() {
    cin >> n >> m >> d;
    long double ans = 0.0;
    if(d == 0.0) ans = (m-1LL) / n;
    else ans = (m-1LL) * 2LL * (n-d) / n / n;

    cout << setprecision(14) << ans << endl;
}