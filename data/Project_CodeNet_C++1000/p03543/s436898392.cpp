#include <bits/stdc++.h>
using namespace std;
 
int main() { 
  int a , b , c , d , e ;
  cin>> a;
  e=a%10;
  d=(a%100-e)/10;
  c=(a%1000-10*b-e)/100;
  b=(a-100*c-10*b-e)/1000;
  if ((b==c&c==d)||(c==d&d==e)){
   cout << "Yes" << endl;
  }
  else{
   cout << "No" << endl;
  }
}
