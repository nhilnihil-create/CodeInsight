#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)

int main() {
  int n, t=15; cin>>n;
  vector<int> d(n); rep(i,n) cin>>d[i];
  sort(d.begin(),d.end());
  int c[2] = {0,0};
  rep(i,n) {
    t = min(t, d[i]-c[i&1]);
    c[i&1] = d[i];
  }
  t = min(t, 24-c[0]-c[1]);
  cout << t << endl;
  return 0;
}
