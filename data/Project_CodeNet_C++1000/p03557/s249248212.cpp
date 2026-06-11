#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
  int N;
  cin >> N;
  vector<int> a(N), b(N), c(N);
  for(int i=0;i<N;i++) cin >> a[i];
  for(int i=0;i<N;i++) cin >> b[i];
  for(int i=0;i<N;i++) cin >> c[i];
  sort(a.begin(), a.end());
  sort(c.begin(), c.end());
  ll ans = 0;
  for(int i=0;i<N;i++){
    ans += ((lower_bound(a.begin(), a.end(), b[i])) - a.begin()) * (N - ((upper_bound(c.begin(), c.end(), b[i])) - c.begin()));
  }
  cout << ans << endl;
  return 0;
}
  