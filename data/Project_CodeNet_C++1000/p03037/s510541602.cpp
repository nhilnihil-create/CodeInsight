#include <bits/stdc++.h>
using namespace std;

int main() {

  int n,m,l,r,ml,mr;
  cin >> n >> m;
  
  ml = 0;
  mr = n;
  
  for ( int i = 0; i < m; i++){
    cin >> l >> r;
    ml = max(ml,l);
    mr = min(mr,r);
  }
  
  if ( ml <= mr ){
    cout << mr - ( ml - 1 ) << endl;
  }else{
    cout << 0 << endl;
  }
  
}