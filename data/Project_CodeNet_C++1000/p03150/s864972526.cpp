#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  string S; cin >> S;
  int N = S.size();
  
  rep(i, 7) {
    string T = S.substr(i, N-7);
    string R = S.substr(0, i) + S.substr(i+N-7);
    if(R == "keyence") {
      cout << "YES" << endl;
      return 0;
    }
  }
  
  cout << "NO" << endl;
  
  
}
