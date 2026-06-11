#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d;
  cin >> a >> b;
  c=(a+b)/2;
  d=c+1;
  cout << d*((a+b)%2)+c*(1-(a+b)%2)  << endl;
}