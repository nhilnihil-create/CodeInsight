#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int N, Q; cin >> N >> Q;
  string S; cin >> S;
  vector<int> n(N, 0);
  rep(i, N-1) {
    if(S[i] == 'A' && S[i+1] == 'C') n[i+1] = n[i] + 1;
    else n[i+1] = n[i];
  }
  //rep(i, N) cout << n[i] << endl;
  
  rep(i, Q) {
    int l, r; cin >> l >> r;
    cout << n[r-1]-n[l-1] << endl;
  }
  


}