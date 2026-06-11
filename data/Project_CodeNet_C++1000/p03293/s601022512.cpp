#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  string s,t,ss = "";
  cin >> s >> t;
  int n = s.size();
  bool ok = false;
  REP(i,n){
    REP(j,n){
      ss.push_back(s.at((i+j)%n));
    }
    if(t == ss) ok = true;
    ss = "";
  }
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}
