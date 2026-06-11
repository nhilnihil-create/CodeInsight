#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
using namespace std;

int main() {
  int n,CH; cin>>n>>CH;
  vector<int> s(n),t(n),c(n);
  rep(i, n) {
    cin>>s[i]>>t[i]>>c[i];
    s[i]--; c[i]--;
  }
  vector<int> y(100005, 0);
  rep(ch, CH) {
    vector<int> x(100005, 0);
    rep(i, n) {
      if (c[i]==ch) {
        x[s[i]]++;
        x[t[i]]--;
      }
    }
    rep(i, 100004) x[i+1]+=x[i];
    rep(i, 100002) {
      if (x[i]>0) y[i]++;
    }
  }
  int res=0;
  rep(i, 100002) res=max(res, y[i]);
  cout<<res<<endl;
}