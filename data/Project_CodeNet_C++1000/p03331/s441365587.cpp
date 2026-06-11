#include <bits/stdc++.h>
using namespace std;
int sed(int i){
  int sum = 0;
  while(i > 0){
    sum += i % 10;
    i /= 10;
  }
  return sum;
}
int main(){
  int n;
  cin >> n;
  if(n == 10 || n == 100 || n == 1000 || n == 10000 || n == 100000) {cout << 10 << endl; return 0;}
  else cout << sed(n) << endl;
}
  
