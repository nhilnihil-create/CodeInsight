#include <bits/stdc++.h>
using namespace std;


int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  bool flag = 0;
  if(abs(a-c)<=d) flag=1;
  else if(abs(a-b)<=d&&abs(b-c)<=d) flag = 1;
  cout << (flag?"Yes":"No") << endl;
}