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
  vector<int> A(N), B(N);
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];
  
  int s = 0;
  rep(i, N) s += (A[i]-B[i]);
  if(s < 0) {
    cout << -1 << endl;
    return 0;
  }
  
  vector<int> p(0), m(0);
  int ms = 0;
  rep(i, N) {
    int k = A[i]-B[i];
    if(k > 0) p.push_back(k);
    if(k < 0) {
      m.push_back(k);
      ms += -k;
    }
  }
  
  sort(all(p));
  reverse(all(p));
  
  int ans = m.size();
  rep(i, p.size()) {
    if(ms <= 0) {
      cout << ans << endl;
      return 0;
    }
    ms -= p[i];
    ans++;
  }
  
  cout << ans << endl;


    

}