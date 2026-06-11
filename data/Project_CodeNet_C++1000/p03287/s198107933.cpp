#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,s,n) for (int i = (s); i < (n); ++i)
#define rrep(i,n,g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define len(x) (int)(x).size()
#define dup(x,y) (((x)+(y)-1)/(y))
#define pb push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n; ll m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i,0,n) cin >> a[i];
  map<ll,ll> p;
  ll k = 0, ans = 0;
  p[0]++;
  rep(i,0,n) {
    k += a[i];
    k %= m;
    ans += p[k];
    p[k]++;
  }
  cout << ans << endl;
  return 0;
}
