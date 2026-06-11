#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y,z,N,Y;
  x = -1;
  y = -1;
  z = -1;
  cin >> N >> Y;
  for(a=0;a<=N;a++){
    for(b=0;b<=N;b++){
      c = N - a - b;
      if(c>=0){
        if(10000*a+5000*b+1000*c == Y && a + b + c == N){
          x = a;
          y = b;
          z = c;
          break;
          }
      }
    }
  }
  cout << x << " " << y << " " << z << " " << endl; 
}