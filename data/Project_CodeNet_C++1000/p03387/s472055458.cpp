#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  vector<int> v(3);
  rep (i, 3) cin >> v[i];

  int count = 0;
  rep (i, 3){
    if (v[i] % 2 == 0) ++count;
  }

  int ans = 0;
  if (count == 2){
    rep (i, 3){
      if (v[i] % 2 == 0) ++v[i];
    }
    ++ans;
  } else if (count == 1){
    rep (i, 3){
      if (v[i] % 2 == 1) ++v[i];
    }
    ++ans;
  }
  sort(v.begin(), v.end());
  ans += (v[2] - v[0]) / 2;
  ans += (v[2] - v[1]) / 2;
  cout << ans << endl;
  return 0;
}