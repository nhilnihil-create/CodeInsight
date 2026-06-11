#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  string s, t; cin >> s >> t;
  
  sort(all(s));
  sort(all(t));
  reverse(all(t));
  
  if(s < t) cout << "Yes" << endl;
  else cout << "No" << endl;

}