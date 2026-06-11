#include <bits/stdc++.h>
using namespace std;

int main(){
  int x;
  cin >> x;
  
  int ans = 1;
  for(int i = 2; i < 40; i++){
    int k = i * i;
    while(k <= x){
      ans = max(ans, k);
      k *= i;
    }
  }
  
  cout << ans << endl;
}