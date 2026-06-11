#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n,k,ans=1;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  if (n == k) {
    cout << ans << endl;
    return 0;
  } else {
    n -= k;
    k--;
    while(n>0) {
      ans++;
      n -= k;
    }
  }
  cout << ans << endl;
  return 0;
}