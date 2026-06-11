#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int a,b,count = 0;
 cin >> a >> b;
 
  for (; a <= b;a++){
    int v,w,x,y,z;
    v = a / 10000;
    w = a / 1000 % 10;
    x = a / 100 % 10;
    y = a / 10 % 10;
    z = a / 1 % 10;
    if(v==z && w==y){
      count++;
    }
  }
 cout << count << endl;
 
}