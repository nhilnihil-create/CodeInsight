#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
#define _GLIBCXX_DEBUG

signed main() {
  int N, H; cin >> N >> H;
  vector<pair<int,int>> k(N);
  rep(i, N) {
    int a, b; cin >> a >> b;
    k[i] = make_pair(a, b);
  }
  
  sort(all(k));
  reverse(all(k));
  int A = k[0].first, B = k[0].second;
  k[0].second = 0;
  
  vector<int> b(N);
  rep(i, N) b[i] = k[i].second;
  sort(all(b));
  reverse(all(b));
  
  int i = 0;
  H -= B;
  int ans = 0;
  if(H <= 0) {
    cout << ans+1 << endl;
    return 0;
  }
  while(b[i] >= A) {
    H -= b[i];
    i++;
    ans++;
    if(H <= 0) {
      cout << ans+1 << endl;
      return 0;
    }
  }
  cout << ans+1+(H+A-1)/A << endl;



}
