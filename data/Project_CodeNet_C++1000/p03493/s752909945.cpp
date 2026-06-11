#include <bits/stdc++.h>
using namespace std;

int main() {
  // ここにプログラムを追記
  int a;
  cin >> a;
  if(a%3==0&&!(a==111)){
    cout << 0;
  }else if(a%3==0){
    cout << 3;
  }else if(a%3==2){
    cout << 2;
  }else{
    cout << 1;
  }
  
}