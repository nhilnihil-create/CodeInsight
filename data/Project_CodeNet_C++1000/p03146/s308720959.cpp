#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  
  int c[10000000];
  memset(c,0,sizeof(c));
  ++c[n];
  
  int res = 1;
  while(true){
    ++res;
    if(n % 2 == 0){
      n /= 2;
    }else{
      n *= 3;
      ++n;
    }
    
    if(c[n] == 0){
      ++c[n];
    }else{
      break;
    }
  }
  
  cout << res <<endl;
}