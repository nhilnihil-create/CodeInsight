#include <bits/stdc++.h>
using namespace std;

// repetition
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define NREP(i, n) FOR(i, 1, n + 1)
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)
#define RREP(i, n) RFOR(i, n, 0)
#define RNREP(i, n) RFOR(i, n, 1)

// debug
#define test(x) cout << #x << " = " << x << endl

// answer output
#define Yes(c) cout << ((c) ? "Yes" : "No") << endl;
#define YES(c) cout << ((c) ? "YES" : "NO") << endl;
#define yes(c) cout << ((c) ? "yes" : "no") << endl;
 
#define possible(c) cout << ((c) ? "possible" : "impossible") << endl;
#define POSSIBLE(c) cout << ((c) ? "POSSIBLE" : "INPOSSIBLE") << endl;

int main() {
  
  string s;
  cin >> s;
  
  if ( s[0] != 'A' ){
    cout << "WA" << endl;
    return 0;
  }
  
  int ichi,hantei = 0,count = 0;
  
  for ( int i = 2; i < s.size() -1; i++){
    if ( s[i] == 'C' ){
      hantei = 1;
      ichi = i;
      count++;
    }
  }
  
  if ( hantei == 0 || count >= 2 ){
    cout << "WA" << endl;
    return 0;
  }
  
  for ( int i = 1; i < s.size(); i++){
    if ( i == ichi ){
      continue;
    }
    if ( s[i] < 97 || s[i] > 122 ){
      cout << "WA" << endl;
      return 0;
    }
  }
  
  cout << "AC" << endl;

}