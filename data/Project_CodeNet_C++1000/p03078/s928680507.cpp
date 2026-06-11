#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long mod = 1000000007LL;

int main() {
  ll x, y, z, k;
  cin >> x >> y >> z >> k;
  vll a(x);
  rep(i,x) cin >> a[i];
  vll b(y);
  rep(i,y) cin >> b[i];
  vll c(z);
  rep(i,z) cin >> c[i];
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  sort(b.begin(),b.end());
  reverse(b.begin(),b.end());
  sort(c.begin(),c.end());
  reverse(c.begin(),c.end());
  vll ab;
  rep(i,x)rep(j,y) ab.push_back(a[i]+b[j]);
  ll m = ab.size();
  sort(ab.begin(),ab.end());
  reverse(ab.begin(),ab.end());
  vll ans;
  rep(i,min(k,m))rep(j,z) ans.push_back(ab[i]+c[j]);
  sort(ans.begin(),ans.end());
  reverse(ans.begin(),ans.end());
  rep(i,k) cout << ans[i] << endl;
  return 0;
}