#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, x;
  cin >> N;
  x = N /100 % 10;
  
  if(N <= x * 111) cout << x * 111 << endl;
  else cout << (x * 111) + 111 << endl;
}