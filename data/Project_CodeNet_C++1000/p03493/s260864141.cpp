#include <bits/stdc++.h>
using namespace std;

int main(){
  int num,ans = 0;
  
  cin >> num;
  
  while (num > 0){
    if ((num % 10) == 1){
      ans++;
    }
    num = num / 10;
  }
    
    cout << ans << endl;
}