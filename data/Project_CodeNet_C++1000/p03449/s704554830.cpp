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
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i,0,n) cin >> a[i];
  rep(i,0,n) cin >> b[i];
  vector<int> sa(n), sb(n);
  sa[0] = a[0], sb[n-1] = b[n-1];
  rep(i,1,n) sa[i] = a[i] + sa[i-1];
  rrep(i,n-1,0) sb[i] = b[i] + sb[i+1];
  int ans = 0;
  rep(i,0,n) {
    ans = max(ans, sa[i] + sb[i]);
  }
  cout << ans << endl;
  return 0;
}