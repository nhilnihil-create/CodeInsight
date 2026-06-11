#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int a,b,k;
  cin >> a >> b >> k;
  
  int i = min(a,b),count = 0;
  
  while(true){
    if ( a % i == 0 && b % i == 0){
      count++;
    }
    if ( count == k ){
      cout << i << endl;
      return 0;
    }
    i--;
  }
 
}
