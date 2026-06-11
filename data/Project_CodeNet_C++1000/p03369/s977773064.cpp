#include <bits/stdc++.h>
using namespace std;

int main() {
  // ここにプログラムを追記
  string S;
  int x=7;
  cin>> S;
  if(S.at(0)=='o') x++;
  if(S.at(1)=='o') x++;
  if(S.at(2)=='o') x++;
  cout<<x*100<<endl;
 
}
