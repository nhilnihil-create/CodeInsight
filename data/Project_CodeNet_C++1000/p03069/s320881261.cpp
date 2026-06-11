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
  string S; cin >> S;
  
  vector<int> s(0);
  int k = 1;
  rep(i, N-1) {
    if(S[i] == S[i+1]) k++;
    else {
      s.push_back(k);
      k = 1;
    }
  }
  s.push_back(k);
  
  if(s.size() == 1) {
    cout << 0 << endl;
    return 0;
  }
  
  
  
  int ans = 0;
  int a = 0;
  if(S[0] == '#') {
    for(int i=1; i<(int)(s.size()); i+=2) a += s[i];
    ans = a;
    s.push_back(0);
    for(int i=1; i<(int)(s.size()); i+=2) {
      ans = min(ans, a + s[i-1] - s[i]);
      a = a + s[i-1] - s[i];
    }
    cout << ans << endl;
  } else {
    if(s.size() == 2) {
      cout << 0 << endl;
      return 0;
    }
    for(int i=0; i<(int)(s.size()); i+=2) a += s[i];
    ans = a;
    s.push_back(0);
    for(int i=1; i<(int)(s.size()); i+=2) {
      //cout << ans << endl;
      ans = min(ans, a - s[i-1]);
      a = a - s[i-1] + s[i];
    }
    cout << ans << endl;
  }

}