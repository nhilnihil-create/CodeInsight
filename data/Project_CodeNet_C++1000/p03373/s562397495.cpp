#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  
  int max;
  int min1;
  int maxnedan;
  int minnedan;
  
  if (x>y){
    max = x;
    min1 = y;
    maxnedan = a;
  }
  else if (x < y){
    max = y;
    min1 = x;
    maxnedan = b;
  }
  
  int total;
  if (a+b > c*2){
    total = 2*c*min1 + min(c*2,a)*(x - min1) + min(c*2,b)*(y - min1);
  }
  else{
    total = a*x + b*y;
  }
  
  cout << total << endl;
}