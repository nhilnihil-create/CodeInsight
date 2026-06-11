#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y){
  if(y == 0){
    return x;
  }
  return gcd(y,x%y);
}

int main(){
  int n;
  cin >> n;
  
  int a[n];
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }
  
  int res = a[0];
  for(int i = 0; i < n; ++i){
    res = gcd(res,a[i]);
  }
  
  cout << res << endl;
}