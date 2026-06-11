#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B;
  cin >> A >> B;
  int count = 0;
  for(; A <= B; A++){
    int up, down, down1, down2;
    up = A / 1000;
    down = A % 100;
    down1 = down / 10;
    down2 = down % 10;
    down = 10 * down2 + down1;
    if(up == down){
      count += 1;
    }
  }
  cout << count << endl;
}