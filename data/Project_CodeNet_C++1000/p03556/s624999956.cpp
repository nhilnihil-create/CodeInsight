#include <bits/stdc++.h>
using namespace std;

int main() {
 
  int n;
  cin >> n;
  
  int ans,a = 1;
  
  while(true){
    ans = a * a;
    if ( ans <= n ){
      a++;
    }else{
      cout << ( a - 1 ) * ( a - 1) << endl;
      return 0;
    }
  }
    
}

