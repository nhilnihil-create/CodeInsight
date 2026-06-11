#include <bits/stdc++.h>
using namespace std;
 
int dsum(int A){
  int tans = 0;
  while (A!=0){
    tans += A%10;
    A /= 10;
  }
  return tans; 
}

int main() {
  int N;
  cin >> N;
  int ans = N;
  for (int i=1; i < N ; i++){
    if (dsum(i) + dsum(N-i) < ans){
      ans = dsum(i) + dsum(N-i);
//      cout << i << "_"<< dsum(i) << " "<< N-i << "_" << dsum(N-i) << endl;
    }
  }
  
  cout << ans << endl;
  
} 
