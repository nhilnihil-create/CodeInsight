#include <bits/stdc++.h>
using namespace std;

int main() {
  // ここにプログラムを追記
  int a;
  int b;
  cin >> a >> b;
  double z = (a+b);
  double x= z /2;
  int y = static_cast<int>(x);
  if(y < x){
  	cout << y +1  << endl;
  }else{
  	cout << y << endl;
  }
}