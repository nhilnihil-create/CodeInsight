#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  vector<int> v(3);
  rep (i, 3) cin >> v[i];
  sort(v.begin(), v.end());

  int ans;
  int sum = v[0] + v[1] + v[2];
  if ((sum % 2) == ((v[2] * 3) % 2)){
    ans = (v[2] * 3 - sum) / 2;
  } else {
    ans = ((v[2] + 1) * 3 - sum) / 2;
  }
  cout << ans << endl;
  return 0;
}