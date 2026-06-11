#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int t,goukei = 0,md = 0;

  for ( int i = 0; i < 5; i++){
    cin >> t;
    if ( t % 10 == 0 ){
      goukei += t;
    }else{
      goukei += ( ( ( t / 10 ) + 1 ) * 10 );
      md = max(md,10 - (t % 10));
    }
    
  }
  
  cout << goukei - md << endl;  
  
}