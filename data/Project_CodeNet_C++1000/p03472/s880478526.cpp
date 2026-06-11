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
  int n, h;
  cin >> n >> h;
  int ma = 0;
  vector<int> bs(n);
  rep(i,0,n) {
    int a, b;
    cin >> a >> b;
    ma = max(ma, a);
    bs[i] = b;
  }
  sort(rall(bs));
  int ans = 0;
  rep(i,0,n) {
    if (bs[i] < ma) break;
    ans++;
    h -= bs[i];
    if (h <= 0) {
      cout << ans << endl;
      return 0;
    }
  }
  ans += dup(h, ma);
  cout << ans << endl;
  return 0;
}