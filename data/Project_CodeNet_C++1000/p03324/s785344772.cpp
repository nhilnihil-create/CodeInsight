#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int d, n;
  cin >> d >> n;
  
  
  long long num = 1;
  for(int i=0; i<d; i++){
    num = num * 100;
  }
  
  if(n!=100){
  cout << num * n << endl;
  }
  else{
  cout << 101 * num << endl;
  }
}
