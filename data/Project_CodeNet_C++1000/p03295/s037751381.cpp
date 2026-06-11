#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;


int main(){
  int n, m; cin >> n >> m;
  vector<pair<int, int>> p(m);
  rep(i, m){
    cin >> p[i].first >> p[i].second;
  }
  sort(p.begin(), p.end());
  int ans = 0, maxa = -1, minb = -1;
  rep(i, m){
    int a = p[i].first, b = p[i].second;
    if(a < minb){
      maxa = max(maxa, a);
      minb = min(minb, b);
    }
    else{
      maxa = a;
      minb = b;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
