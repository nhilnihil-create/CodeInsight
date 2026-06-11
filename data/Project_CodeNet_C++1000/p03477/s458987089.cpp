#include <bits/stdc++.h>
using namespace std;

int main() {
  //左の重り
  int a,b;
  //右の重り
  int c,d;
  
  cin >> a >> b >> c >> d;
  
  int left = a + b;
  int right = c + d;
  
  if(left > right){
    cout << "Left" << endl;
  }else if(left < right){
    cout << "Right" << endl;
  }else{
    cout << "Balanced" << endl;
  }
}
