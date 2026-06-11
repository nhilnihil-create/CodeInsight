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
  
  int mn = 10000,t;
  
  for ( int i = 0; i < s.size() - 2; i++){
    t = ( s[i] - '0' ) * 100 + ( s[i+1] - '0' ) * 10 + ( s[i+2] - '0' ) ;
    if ( mn > abs( 753 - t ) ){
      mn = abs(753-t);
    }
  }
  
  cout << mn << endl;

}