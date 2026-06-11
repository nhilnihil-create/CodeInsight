#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
//#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int N; cin >> N;
  vector<int> x(N), y(N), h(N);
  rep(i, N) cin >> x[i] >> y[i] >> h[i];

  
  rep(X, 101) rep(Y, 101) {
    int H = 0;
    int n = 0;
    while(H < 1) {
      if(h[n] > 0) H = abs(x[n]-X) + abs(y[n]-Y) + h[n];
      n++;
    }
    rep(i, N) {
      if(max(H - abs(x[i]-X) - abs(y[i]-Y) , 0) != h[i]) break;
      if(i == N-1) {
        cout << X << " " << Y << " " << H << endl;
        return 0;
      }
    }
  }

}
