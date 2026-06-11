#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int N; cin >> N;
  vector<int> x(N), y(N), t(N);
  rep(i, N) cin >> t[i] >> x[i] >> y[i];
  
  int X=0, Y=0, T=0;
  rep(i, N) {
    if(abs(X-x[i])+abs(Y-y[i]) > t[i]-T || (abs((abs(X-x[i])+abs(Y-y[i])-(t[i]-T))))%2 == 1) {
      cout << "No" << endl;
      return 0;
    }
    X = x[i];
    Y = y[i];
    T = t[i];
  }
  cout << "Yes" << endl;
  return 0;

}