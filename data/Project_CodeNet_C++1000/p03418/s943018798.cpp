#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

ll n, k;

int main() {
    cin >> n >> k;
    ll ans = 0;
    for(ll b = 1; b <= n; ++b) {
        ll sub = max(b-k, 0LL);
        ll sum = (n/b)*sub;
        ll rest = n - (n/b)*b;
        sum += max(0LL, rest-k+1);
        ans += sum;
    }
    if(k == 0) cout << ans-n << endl;
    else cout << ans << endl;
}