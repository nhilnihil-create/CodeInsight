#include <bits/stdc++.h>
using namespace std;

int main(){
  int s;
  int h,t,o;
  cin >> s ;
  h = s / 100;
  t = (s - h * 100) / 10;
  o = s - h * 100 - t * 10;
  cout << h + t + o << endl;
}