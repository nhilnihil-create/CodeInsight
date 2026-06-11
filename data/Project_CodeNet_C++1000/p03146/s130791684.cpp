#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
  int s,t;
  cin >> s;
  t = 1;
  
  
  if(s == 1){
    cout << 4 << endl;
  }
  
  else if(s == 2){
    cout << 4 << endl;
  }
  
 else{
  for(int i=1; i<1e6+2; i++){
    if(s == 1){
      t++;
      break;
    }
    if(s%2 == 0){
      s /= 2;
      t++;
    }
    else{
      s = 3*s+1;
      t++;
    }
  }
   cout << t << endl;
 }
  
	return 0;
}
