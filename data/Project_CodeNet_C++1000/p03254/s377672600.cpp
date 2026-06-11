#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  
  sort(a.begin(), a.end());
  int ans = 0;
  rep(i,n) {
    x -= a[i];
    if (x < 0) break;
    ans++;
  }
  
  if (x > 0)
    cout << ans-1 << endl;
  else
  cout << ans << endl;
}