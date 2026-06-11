#include <bits/stdc++.h>
 
using namespace std;
int main() {
  int N,A,B;
  int keep,sum = 0;
  int i,y;
  cin >> N >> A >> B;
  for (i = 0; i <= N; i++) {
    keep = 0;
    y = i;
    while(y > 0){
      keep += (y % 10);
      y = y / 10;
    }
    if (A <= keep){
      if(keep <= B){
        sum += i; 
      }
    }
  }
  cout << sum;
}