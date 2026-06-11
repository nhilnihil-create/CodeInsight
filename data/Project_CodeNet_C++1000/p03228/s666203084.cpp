#include <bits/stdc++.h>
using namespace std;
using ll=long long;


int main() {
  int a, b, c;
  cin >>a >> b >> c;
  
  for(int i=0;i<c;i++){
      if(i%2==0){
        b=b+(a/2);
        a=a/2;
      }
      else{
      a=a+(b/2);
      b=b/2;
      }
  }
  
  cout << a << " " << b <<endl;
}
    
    