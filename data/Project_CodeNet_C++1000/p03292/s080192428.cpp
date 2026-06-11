#include<iostream>
using namespace std;

int main(){
  int a,b,c,max=0,min=100;
  cin >> a >> b >> c;
  if(a>max) max=a;
  if(b>max) max=b;
  if(c>max) max=c;
  if(a<min) min=a;
  if(b<min) min=b;
  if(c<min) min=c;
  cout << max-min;
}