#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, m;
  cin>>n>>m;
  vector<int> l(m), r(m);
  int maxl=1, minr=n+1;
  rep (i, m) cin>>l.at(i)>>r.at(i);
  rep (i, m) {
    maxl = max(maxl, l.at(i));
    minr = min(minr, r.at(i));
  }
  if(minr<maxl) cout<<0<<endl;
  else cout<<minr-maxl+1<<endl;
}