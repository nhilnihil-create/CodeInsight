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
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i,0,n) cin >> v[i];
  vector<P> p1(100001),p2(100001);
  rep(i,0,n) {
    if (i % 2 == 0) {
      p1[v[i]].fi++; p1[v[i]].se = v[i];
    } else {
      p2[v[i]].fi++; p2[v[i]].se = v[i];
    }
  }
  sort(rall(p1)); sort(rall(p2));
  int ans;
  if (p1[0].se != p2[0].se) {
    ans = n - p1[0].fi - p2[0].fi;
  } else {
    int k = max(p1[0].fi + p2[1].fi, p1[1].fi + p2[0].fi);
    ans = n-k;
  }
  cout << ans << endl;
  return 0;
}
