#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> l(n), r(n);
    for (int i = 1; i <= n-1; i++) {
      l[i] = __gcd(l[i-1], a[i-1]);
    }
    for (int i = n-2; i >= 0; i--) {
      r[i] = __gcd(r[i+1], a[i+1]);
    }
    int ans = 0;
    rep(i,n) {
      ans = max(ans, __gcd(l[i],r[i]));
    }
    cout << ans << endl;
    return 0;
}