#include <bits/stdc++.h>
using namespace std;

int main() {
  int r,g,b,num;
  int cnt = 0;
  
  cin >> r >> g >> b >> num;
  
  for(int i = 0; i <= 3000; i++){
    for(int j = 0; j <= 3000; j++){
      if(num - (r * i + g * j) < 0) continue;
      if((num - (r * i + g * j)) % b == 0)cnt++;
    }
  }
  
  cout << cnt;
}
