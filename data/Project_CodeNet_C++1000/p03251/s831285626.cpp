#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n,m,x,y,a,b;
  cin >> n >> m >> x >> y;
  
  int MXx = -101,MNy = 101;
  
  for ( int i = 0; i < n; i++){
    cin >> a;
    MXx = max(MXx,a);
  }
  
  for ( int i = 0; i < m; i++){
    cin >> b;
    MNy = min(MNy,b);
  }
  
  for ( int i = x + 1; i <= y; i++){
    if ( MXx < i && i <= MNy ){
      cout << "No War" << endl;
      return 0;
    }
  }
  
  cout << "War" << endl;
  
  return 0; 
 
}