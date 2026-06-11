#include<bits/stdc++.h>
using namespace std;

int main (void){
  int k,ans;
  cin >> k;

  if(k % 2 == 1){
    ans = (k - 1) / 2 * (k + 1) / 2;
    cout << ans << "\n";
  }else{
    ans = k/2 * k/2;
    cout << ans << "\n";
  }

  return 0;
}