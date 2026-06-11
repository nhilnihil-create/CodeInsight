#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  double c;
  cin >> a >> b;
  c = (a + b)/2.0;
  if((int)(10*c)%10==0){
    cout << c << endl;
  }else{
    cout << (int)c + 1 << endl;
  }
}