#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  int a,b,c,d;
  
  cin >> N;
  
  //1の桁取得
  a = N % 10;
  
  //10の桁取得
  b = (N % 100 - a) / 10;
  
  //100の桁取得
  c = (N % 1000 - 10 * b - a) / 100;
  
  //1000の桁取得
  d = (N % 10000 - 100 * c - 10 * b - a) / 1000;
  
  //よい整数かどうかを判別
  if ( a == b && b == c){
    cout << "Yes" << endl;
  }
  else if ( b == c && c == d){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}