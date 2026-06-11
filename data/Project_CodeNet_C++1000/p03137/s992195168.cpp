#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,s,n) for (int i = (s); i < (n); ++i)
#define rrep(i,n,g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define len(x) (int)(x).size()
#define dup(x,y) (((x)+(y)-1)/(y))
#define append push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> x(m);
  rep(i,0,m) cin >> x[i];
  if (n >= m) {
    cout << 0 << endl;
    return 0;
  }
  sort(all(x));
  vector<int> d(m-1);
  int ans = 0;
  rep(i,0,m-1) {
    d[i] = x[i+1] - x[i];
    ans += d[i];
  }
  sort(rall(d));
  rep(i,0,n-1) ans -= d[i];
  cout << ans << endl;
  return 0;
}
