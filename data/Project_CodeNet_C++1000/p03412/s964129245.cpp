#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()

int main() {
  i64 N;
  cin >> N;
  vector<i64> a(N), b(N);
  i64 ans = 0;
  for(int i = 0;i < N;i++) cin >> a[i] ;
  for(int i = 0;i < N;i++) cin >> b[i];
  for(int i = (1 << 28);i > 0; i >>= 1) {
    for(auto& x: a) x = x & ((i << 1) - 1);
    for(auto& x: b) x = x & ((i << 1) - 1);
    sort(all(b));
    int bit = 0;
    for(auto x: a) { 
      bit += (lower_bound(all(b), 2 * i - x) - lower_bound(all(b), i - x)) + (lower_bound(all(b), 4 * i - x) - lower_bound(all(b), 3 * i - x));
    }
    ans |= i * !!(bit & 1);
    
  }
  cout << ans << endl;
}
