#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n,m,x,a;
  cin >> n >> m >> x;
  
  int cntMx = 0,cntMn = 0;
  
  for ( int i = 0; i < m; i++){
    cin >> a;
    if ( a < x ){
      cntMn++;
    }else if ( a > x ){
      cntMx++;
    }
  }
  
  cout << min(cntMn,cntMx) << endl;
    
}