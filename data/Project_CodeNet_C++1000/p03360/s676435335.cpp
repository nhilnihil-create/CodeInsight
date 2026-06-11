#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b ,c ,k,d;
  int ans =0 ;
 
  cin >> a >> b >> c >> k;
  d = max ( a , max ( b,c));
  int e=d ;
  ans =  a + b +c -d;
  for ( int i=0 ; i< k ; i++){
    e*=2 ;
  }
       ans +=e;
       cout << ans << endl;
}