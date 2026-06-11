#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N ;
  cin >> N ; 
  int ans = 100 ;
  for ( int i=0 ; i<N ;i++){
  int x ;
  cin >> x ;
    int count = 0 ;
  for ( int j = x ; j %2 ==0 ; ){
    j /=2 ;
      count ++ ;
  }
    ans = min ( ans , count ) ;
  }
  cout << ans << endl;
}
