#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
using Graph = vector<vector<int>>;
int main() {
  string S,T;
  cin >> S >> T;
  int s = S.size();
  int t = T.size();
  if (t-s > 0) {
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  for(int i=s-t; i>=0; i--) {
    bool bubun = true;
    FOR(j,i,i+t) {
      if (S[j] == '?') continue;
      if (S[j] == T[j-i]) continue;
      bubun = false;
    }
    if (bubun) {
      FOR(j,0,s-t) {
        if(S[j] == '?') S[j] = 'a';
      }
      FOR(j,i,i+t) {
        S[j] = T[j-i];
      }
      FOR(j,i+t,s) {
        if(S[j] == '?') S[j] = 'a';
      }
      cout << S << endl;
      return 0;
    }
  }
  cout << "UNRESTORABLE" << endl;
  
  return 0;
}