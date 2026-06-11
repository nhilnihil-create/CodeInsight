#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, a = 0;
  cin >> N;
  int b = N;
  
  while(b){
  a += b % 10;
  b /= 10;
  }
  
  if(N % a == 0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}