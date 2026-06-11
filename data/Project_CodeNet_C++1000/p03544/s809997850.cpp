#include <bits/stdc++.h>
using namespace std;
long long ryuka(int x){
  long long a = 2;
  long long b = 1;
  
  if(x == 0){
    return 2;
  }
  else if(x == 1){
    return 1;
  }
  else{
  for(int i = 0; i < x; i++){
    long long d = b;
    b = a + b;
    a = d;
  }
  return a;
  }
}
 
int main() {
  int n;
  cin >> n;
  cout << ryuka(n) << endl;
}