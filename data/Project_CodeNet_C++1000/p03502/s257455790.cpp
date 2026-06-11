#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  string ans = "No";
  int X = 0;
  int tN = N;
  while (tN>0){
    X += tN%10;
    tN /= 10;
  }
  if (N%X == 0) ans = "Yes";
  
  cout << ans << endl; 
  
} 
