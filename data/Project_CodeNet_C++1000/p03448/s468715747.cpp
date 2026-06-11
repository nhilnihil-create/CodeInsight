/* ABC087B -Coins */

#include <bits/stdc++.h>
using namespace std;

int func(int B, int C, int X){
  int b = X / 100, c = (X - 100 * b) / 50, cnt_2 = 0;
    while(b >= 0){
      if(b <= B && c <= C) cnt_2++;
      b--; c += 2;
    }
  return cnt_2;
}

int main(){
  int A, B, C, X, cnt = 0;
  cin >> A >> B >> C >> X;
  int a = X / 500;
  while(a >= 0){
    if(a <= A) cnt += func(B, C, X - 500 * a);
    a--;
  }
  cout << cnt << endl;
}
