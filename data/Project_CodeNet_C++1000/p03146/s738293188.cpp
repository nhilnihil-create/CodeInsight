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

int func(int n){
  
  if ( n % 2 == 0 ){
    return n / 2;
  }else{
    return 3 * n + 1;
  }
  
}


int main() {
  
  int s;
  cin >> s;
  
  vector<int> a;
  a.push_back(s);
  
  int i = 1;
  
  while(true){
    a.push_back(func(a[i-1]));
    for ( int j = 0; j < i ; j++){
      if ( a[i] == a[j] ){
        cout << i+1 << endl;
        return 0;
      }
    }
    i++;
  }

}