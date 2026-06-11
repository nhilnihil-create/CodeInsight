#include <bits/stdc++.h>
using namespace std;

int main() {
  // ここにプログラムを追記
  int a,b;
  cin >> a >> b;
  int c=a+b;
  if(c%2==0){
    cout << c/2;
  }
  if(c%2==1){
    cout << c/2+1;
  }
}