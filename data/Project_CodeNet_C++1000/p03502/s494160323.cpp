#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  
  int x = N;
  int k = 0;
  while (N != 0){
    k += N % 10;
    N /= 10;
  }
  
  if (x % k == 0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}