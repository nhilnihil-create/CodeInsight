#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {

  int n;
  cin >> n;
  
  vector<int> t(n);
  rep(i,n) cin >> t[i];
  
  sort(t.begin(), t.end());
  
  t[n-1] /= 2;
  
  int ans = 0;
  rep(i,n) ans += t[i];
  cout << ans << endl;
  
  
  
}
