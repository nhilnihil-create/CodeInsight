#include <bits/stdc++.h>
using namespace std; 
int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int maxi=max(10*a+b+c,max(10*b+a+c,10*c+b+a));
  cout << maxi;
  
}
