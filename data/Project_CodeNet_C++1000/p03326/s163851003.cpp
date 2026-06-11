#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> x(n), y(n), z(n);
    rep(i, n)cin >> x[i] >> y[i] >> z[i];
    
    ll ans = 0;
    rep(i, 2)rep(j, 2)rep(k, 2){
        ll si = -1 + i * 2;
        ll sj = -1 + j * 2;
        ll sk = -1 + k * 2;
        vector<ll> a(n);
        rep(i, n)a[i] = x[i]*si + y[i]*sj + z[i]*sk;
        sort(a.begin(), a.end(), greater<ll>());
        ll sum = 0;
        rep(i, m)sum += a[i];
        ans = max(ans, sum);
    }
    cout << ans << endl;
}