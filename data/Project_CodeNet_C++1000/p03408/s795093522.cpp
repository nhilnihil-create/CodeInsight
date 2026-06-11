#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;

int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  rep(i,n) cin >> a.at(i);
  int m;
  cin >> m;
  vector<string> b(m);
  rep(i,m) cin >> b.at(i);

  int ans = 0;
  rep(i,n){
    int cnt = 0;
    rep(j,n){
      if(a.at(i) == a.at(j)) cnt++;
    }
    rep(j,m){
      if(a.at(i) == b.at(j)) cnt--;
    }
    ans = max(ans,cnt);
  }
  cout << ans << endl;
}
