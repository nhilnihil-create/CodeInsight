#include <bits/stdc++.h>
using namespace std;

int main() {
  // ここにプログラムを追記
  string  a;
  cin >> a;
  int x= 0;
  for (int i=0; i<3;i++){
      if(a.at(i)=='1'){
          x++;
      }
  }


  cout << x << endl;
}
