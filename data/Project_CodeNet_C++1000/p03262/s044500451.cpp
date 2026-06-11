#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

int gcd(int n, int m) {
  if(n < m) swap(n, m);
  if(m == 1) return 1;
  else if(m == 0) return n;
  else return gcd(m, n%m);
}

signed main() {
  int N, X; cin >> N >> X;
  vector<int> x(N);
  rep(i, N) {
    int xx; cin >> xx;
    x[i] = abs(xx-X);
  }
  sort(all(x));
  
  
  int ans = x[0];
  
  rep(i, N) {
    ans = gcd(ans, x[i]);
  }
  
  cout << ans << endl;
  

}
