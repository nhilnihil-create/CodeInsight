#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define int long long
//#define _GLIBCXX_DEBUG

signed main() {
  string S, T; cin >> S >> T;
  int N = S.size();
  vector<int> s(N, 0), t(N, 0);
  vector<int> ss(0), tt(0);
  string a =  "abcdefghijklmnopqrstuvwxyz";
  
  rep(i, N-1) {
    if(S[i] != S[i+1]) s[i] = 1;
    if(T[i] != T[i+1]) t[i] = 1;
  }
  for(char c : a) {
    ss.push_back(count(all(S), c));
    tt.push_back(count(all(T), c));
  }
  sort(all(ss));
  sort(all(tt));
  
  if(s == t && ss == tt) cout << "Yes" << endl;
  else cout << "No" << endl;
}