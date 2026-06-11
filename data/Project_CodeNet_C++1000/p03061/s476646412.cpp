#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
const ll MOD = 1000000007;//998244353;
//gcd(x, y) -> xとyの最大公約数
int gcd(int x, int y){
    return y ? gcd(y, x % y) : x;
}
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n; cin >> n;
   vector<int> a(n);
   rep(i,n)cin >> a[i];
   vector<int> v1, v2;
   v1.push_back(a[0]);
   v2.push_back(a[n-1]);
   rep(i,n-1){
      v1.push_back(gcd(v1[i], a[i+1]));
      v2.push_back(gcd(v2[i], a[n-i-2]));
   }
   int ans = max(v1[n-2], v2[n-2]);
   rep(i,n-2){
      ans = max(ans, gcd(v1[i], v2[n-i-3]));
   }
   cout << ans << endl;
}