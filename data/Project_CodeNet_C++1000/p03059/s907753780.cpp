#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,t;
  cin >> a >> b >> t;
  t=t+0.5;
  int i=a,k=0;
  while(i<=1.0*(t+0.5)){
    i+=a;
    k+=b;
  }
  cout << k << endl;
  return 0;
}
