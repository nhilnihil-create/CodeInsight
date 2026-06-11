#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> v(n+1, 0);
  int a;
  rep(i, n){
    cin >> a;
    ++v[a];
  }
  sort(v.begin(), v.end(), greater<>());
  v.erase(v.begin(), v.begin() + k);
  int ans = 0;
  rep(i, n - k){
    ans += v[i];
  }
  cout << ans << endl;
  return 0;
}