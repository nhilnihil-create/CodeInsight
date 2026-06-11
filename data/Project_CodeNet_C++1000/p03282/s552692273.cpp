#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define intll int long long
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
  string s ; 
  int k ;
  cin >> s >> k ; 
  bool OK = true ;
  int now = 0 ; 
  int x = s.size() - 1 ;
  
  while(OK){
    if(s.at(now) != '1') {
      cout << s.at(now) <<endl ; 
      OK =false ; 
      break ; 
    }
    if(now ==min(x,k-1) ) {
      cout << 1 ;
      OK = false ; 
    }
    now ++ ; 
  }
    
}
