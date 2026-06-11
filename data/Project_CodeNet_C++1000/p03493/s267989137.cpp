#include<bits/stdc++.h>
using namespace std;
int main(){
  int a ;
  int b ;
  cin >> a;
  b = (a/100) + ((a/10)%10) +(a%10);
  cout << b;
}