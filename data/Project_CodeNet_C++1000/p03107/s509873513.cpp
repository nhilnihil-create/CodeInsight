#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  
  int a = 0,b = 0;
  REP(i,n){
    if(s[i] == '1') a++;
    else b++;
  }

  int ans;
  if(a == 0 || b == 0) ans = 0;
  else ans = 2*min(a,b);
  
  cout << ans << endl;
  
}
