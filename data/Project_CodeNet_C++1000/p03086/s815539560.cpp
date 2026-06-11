#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin >> s;
  string model = "ATGC" ;
  int now = 0;
  int ans = 0 ;
  for ( int i=0 ; i < s.size() ; i++){
    bool is = false ;
    for ( int j = 0 ; j<4 ; j++){
      if ( model.at(j) == s.at(i)){
        is = true;
      }
    }
    if ( ! is ) {
      now = 0 ;
  }else  now++;
        ans = max ( ans , now) ;
  }
  cout << ans << endl;
}