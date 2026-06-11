#include <bits/stdc++.h>
using namespace std;
int main(){
  int a , b ; 
  cin >> a >> b ;
  int n = (a+b) ; 
  cout << (n%2)*((n+1)/2) + !(n%2)*(n/2) ; 
}