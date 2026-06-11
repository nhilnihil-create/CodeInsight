#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  int n = s.size(),m = 0;
  if(s[0] != 'A'){
    cout << "WA" << endl;
    return 0;
  }
  REP(i,n){
    if(i > 1 && i < n-1){
      if(s[i] == 'C'){
        m = i;
        break;
      }
    }
  }
  if( m == 0 ){
    cout << "WA" << endl;
    return 0;
  }    
  REP(i,n){
    if(i != 0 && i != m){
      if(s[i] < 'a' || s[i] > 'z'){
        cout << "WA" << endl;
        return 0;
      }
    }
  }
  cout << "AC" << endl;
}
