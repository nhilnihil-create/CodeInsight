#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int ans = 1001001001;
  rep(i,n-k+1) {
    ans = min(ans,min(abs(a[i])+abs(a[i+k-1]-a[i]),abs(a[i+k-1])+abs(a[i+k-1]-a[i])));
  }
  cout << ans << endl;
  return 0;
}