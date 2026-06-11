#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n , m , c;
  cin >> n >> m >> c;
  vector <int> b(m);
  for ( int i=0 ; i<m ; i++){
    cin >> b.at(i);
  }
  int ans = 0 ;
  for ( int i=0 ; i<n ; i++){
     vector <int> a(m);
    int sum=0 ;
    for ( int j=0 ; j<m ; j++){
      cin >> a.at(j) ;
      sum += a.at(j)*b.at(j); 
    }
    if ( sum+c>0){
      ans ++ ;
    }
  }
  cout << ans << endl;
}