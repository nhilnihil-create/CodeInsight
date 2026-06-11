#include <bits/stdc++.h>
using namespace std;
int main(void){
  int a,b,c;
  cin >> a >> b >> c;
  cout << min(b,c) << " ";
  if(c + b - a > 0){
    cout << c + b - a;
  }else{
    cout << 0;
  }
}