#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int m;
  
  cin >> m;
  
  int h = m / 100;
  
  int j = (m - h * 100) / 10;
  
  int i = m - h * 100 - j * 10;
  
  cout << h + j + i
    << endl;
  
  return 0;
  
}