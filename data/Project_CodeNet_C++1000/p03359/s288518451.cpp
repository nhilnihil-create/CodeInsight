#include<bits/stdc++.h>

using namespace std;

int main(){
  
  int res = 0,a,b;
  cin >> a >> b;
  res = a;
  if(b >= a)cout << res << endl;
  else cout << --res << endl;
  
  return 0;
}