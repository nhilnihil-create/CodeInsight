#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N, y, z = 0;
  cin >> N;
  for(int i = 0; i < N; i++){
    int A,x = 0;
    cin >> A;
    while(A % 2 == 0){
      A /= 2;
      x++;
    }
    if(z == 0){
      y = x;
      z++;
    }
    else{
      if(y > x){
        y = x;
      }
    }
  }
  cout << y << endl;
}