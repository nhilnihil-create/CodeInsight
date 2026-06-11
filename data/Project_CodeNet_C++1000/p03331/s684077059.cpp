#include <bits/stdc++.h>
using namespace std;


int main(){

  int N;
  cin >> N;
  int ans = 0;
  if(N % 10 == 0) cout << 10 << endl;
  else{
    while(N > 0){
      ans += N % 10;
      N /= 10;
    }
    cout << ans << endl;
  }

  return 0; 
}