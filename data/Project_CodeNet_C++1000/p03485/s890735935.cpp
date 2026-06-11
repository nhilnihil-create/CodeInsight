#include<bits/stdc++.h>
using namespace std;
int main(){
  double a,b,c;
  cin >> a >> b;
  c = (a + b) / 2.0;
  if (c>int(c)) c+=1.0;
  cout << int(c) << endl;
}
