#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,d;
  bool flag=false,ans=false;
  cin >> a >> b >> c >> d;
  if(a>=b && a-b<=d) flag = true;
  else if(b>=a && b-a<=d) flag = true;
  if(flag && b>=c && b-c<=d) ans = true;
  else if(flag && c>=b && c-b<=d) ans = true;
  if(a>=c && a-c<=d) ans = true;
  else if(c>=a && c-a<=d) ans = true;
  cout << (ans? "Yes":"No") << endl;
  return 0;
}