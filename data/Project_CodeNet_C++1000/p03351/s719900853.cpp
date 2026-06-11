#include<bits/stdc++.h>

using namespace std;

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  bool flg = false;
  if( abs(a-c) <= d) flg = true;
  if( abs(a-b) <= d && abs(b-c) <= d) flg = true;
  
  cout << (flg ? "Yes" : "No") << endl;
}