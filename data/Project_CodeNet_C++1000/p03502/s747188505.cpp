#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int N,x,n;
 int a =0;
 cin >> N;
  n = N;
  while(true){
    x = n%10;
    a += x;
    n = n/10;
    if(n == 0){
      break;
    }
  }
  if(N%a == 0){
    cout << "Yes" <<endl;
  }else{
    cout << "No" <<endl;
  }
}