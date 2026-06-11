#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,M,m;
  cin >> a >> b >> c;  
  m = min(min(a,b),c);
  M = max(max(a,b),c);
  cout << M-m << endl;
} 