#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int main() {
  int n, t;
  cin >> n >> t;
  vector<P> p(n);
  rep(i,n){
    cin >> p[i].first >> p[i].second;
  }
  sort(p.begin(), p.end());
  int ans = 0;
  rep(i,n){
    if(p[i].second <=t) {
      ans = p[i].first;
      break;
    }
  }
  if(ans) cout << ans << endl;
  else cout << "TLE" << endl;
}