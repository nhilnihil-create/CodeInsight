#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,x,y,z;
  x = 0;
  y = 0;
  cin >> N;
  z = N;
  while (z>0){
    x += z%10;
    if (x==1){
      y++;
    }
    z /= 10;
  }
  cout << x <<endl;
}