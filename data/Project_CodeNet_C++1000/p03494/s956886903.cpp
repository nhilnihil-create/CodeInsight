#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  int ans = 1000000000;
  cin >> N;
 
  for(int i = 0; i < N ; i++){
    int min = 0;
    cin >> A;
    
    if(A % 2 != 0){
      ans = 0;
      break;
    }
    
    while (A % 2 == 0){
      A /= 2;
      min++;
    }

    if(ans > min)
      ans = min;
  }
  cout << ans << endl;
}