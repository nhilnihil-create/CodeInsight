#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a, b;
  cin >> a >> b;
  if(a+b == 15) cout << "+" << endl;
  else if(a*b == 15) cout << "*" << endl;
  else cout << "x" << endl;  
  return 0;
}