#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  if(b!=100)
    cout << int(pow(100,a)*b) << endl;
  else
    cout << int(pow(100,a)*(b+1)) << endl;
  return 0;
}