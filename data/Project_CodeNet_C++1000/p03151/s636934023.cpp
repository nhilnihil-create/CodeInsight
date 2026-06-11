#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF=1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  deque<int> c;
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  int ans=0;
  ll res=0;
  rep(i,n) {
    int x=a[i]-b[i];
    if(x<0) {
      ans++;
      res+=-x;
    }
    else if(x>0) c.push_back(x);
  }
  sort(c.begin(),c.end());
  while(res>0) {
    if(c.size()==0) {
      cout << -1 << endl;
      return 0;
    }
    res -= c.back();
    c.pop_back();
    ans++;
  }
  cout << ans << endl;
  return 0;
}
