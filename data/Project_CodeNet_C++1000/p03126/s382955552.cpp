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
  
  int n,m;
  cin >> n >> m;
  
  vector<int> t(m+1,0);
  
  for ( int i = 0; i < n; i++){
    int k;
    cin >> k;
    for ( int j = 0; j < k; j++){
      int a;
      cin >> a;
      t[a]++;
    }
  }
  
  int count = 0;
  
  for ( int i = 0; i < m + 1; i++){
    if ( t[i] == n ){
      count++;
    }
  }
  
  cout << count << endl;

}